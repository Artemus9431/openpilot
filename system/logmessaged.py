#!/usr/bin/env python3
import zmq
from typing import NoReturn

import cereal.messaging as messaging
from cereal.services import SERVICE_LIST
from openpilot.common.logging_extra import SwagLogFileFormatter
from openpilot.system.hardware.hw import Paths
from openpilot.common.swaglog import get_file_handler

ALIGNMENT = 8
SIZE_TAG_BYTES = 8


def _msgq_total_size(payload_size: int) -> int:
  return ((payload_size + SIZE_TAG_BYTES + (ALIGNMENT - 1)) // ALIGNMENT) * ALIGNMENT


def _send_log(sock: messaging.PubSocket, service: str, record: str) -> None:
  msg = messaging.new_message(None, valid=True, **{service: record})
  msg_bytes = msg.to_bytes()
  queue_size = SERVICE_LIST[service].queue_size
  if 3 * _msgq_total_size(len(msg_bytes)) <= queue_size:
    sock.send(msg_bytes)
  else:
    print("WARNING:", service, "too big to publish", len(msg_bytes), "queue_size", queue_size)


def main() -> NoReturn:
  log_handler = get_file_handler()
  log_handler.setFormatter(SwagLogFileFormatter(None))
  log_level = 20  # logging.INFO

  ctx = zmq.Context.instance()
  sock = ctx.socket(zmq.PULL)
  sock.bind(Paths.swaglog_ipc())

  # and we publish them
  log_message_sock = messaging.pub_sock('logMessage')
  error_log_message_sock = messaging.pub_sock('errorLogMessage')

  try:
    while True:
      dat = b''.join(sock.recv_multipart())
      level = dat[0]
      record = dat[1:].decode("utf-8")
      if level >= log_level:
        log_handler.emit(record)

      if len(record) > 2 * 1024 * 1024:
        print("WARNING: log too big to publish", len(record))
        print(record[:100])
        continue

      # then we publish them
      _send_log(log_message_sock, "logMessage", record)

      if level >= 40:  # logging.ERROR
        _send_log(error_log_message_sock, "errorLogMessage", record)
  finally:
    sock.close()
    ctx.term()

    # can hit this if interrupted during a rollover
    try:
      log_handler.close()
    except ValueError:
      pass

if __name__ == "__main__":
  main()
