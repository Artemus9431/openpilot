from openpilot.common.params import Params
from openpilot.system.ui.widgets import Widget
from openpilot.system.ui.widgets.list_view import multiple_button_item, toggle_item
from openpilot.system.ui.widgets.scroller import Scroller

# Description constants
DESCRIPTIONS = {
  "OpenpilotEnabledToggle": (
    "Use the openpilot system for adaptive cruise control and lane keep driver assistance. " +
    "Your attention is required at all times to use this feature."
  ),
  "DisengageOnAccelerator": "When enabled, pressing the accelerator pedal will disengage openpilot.",
  "LongitudinalPersonality": (
    "Standard is recommended. In aggressive mode, openpilot will follow lead cars closer and be more aggressive with the gas and brake. " +
    "In relaxed mode openpilot will stay further away from lead cars. On supported cars, you can cycle through these personalities with " +
    "your steering wheel distance button."
  ),
  "IsLdwEnabled": (
    "Receive alerts to steer back into the lane when your vehicle drifts over a detected lane line " +
    "without a turn signal activated while driving over 31 mph (50 km/h)."
  ),
  "AlwaysOnDM": "Enable driver monitoring even when openpilot is not engaged.",
  'RecordFront': "Upload data from the driver facing camera and help improve the driver monitoring algorithm.",
  "IsMetric": "Display speed in km/h instead of mph.",
  "RecordAudio": "Record and store microphone audio while driving. The audio will be included in the dashcam video in comma connect.",
  "TorqueInterceptorEnabled": "Enable the torque interceptor to control the steering wheel.",
  "RadarInterceptorEnabled": "Enable if you have installed the radar interceptor.",
  "NoMRCC": "Enable if your car does not have stock MRCC.",
  "NoFSC": "Enable if your car does not have stock FSC.",
  "ManualTransmission": "Enable if your car has a manual transmission.",
}


class TogglesLayout(Widget):
  def __init__(self):
    super().__init__()
    self._params = Params()
    items = [
      toggle_item(
        "Enable openpilot",
        DESCRIPTIONS["OpenpilotEnabledToggle"],
        self._params.get_bool("OpenpilotEnabledToggle"),
        icon="chffr_wheel.png",
      ),
      toggle_item(
        "Experimental Mode",
        initial_state=self._params.get_bool("ExperimentalMode"),
        icon="experimental_white.png",
      ),
      toggle_item(
        "Disengage on Accelerator Pedal",
        DESCRIPTIONS["DisengageOnAccelerator"],
        self._params.get_bool("DisengageOnAccelerator"),
        icon="disengage_on_accelerator.png",
      ),
      multiple_button_item(
        "Driving Personality",
        DESCRIPTIONS["LongitudinalPersonality"],
        buttons=["Aggressive", "Standard", "Relaxed"],
        button_width=255,
        callback=self._set_longitudinal_personality,
        selected_index=self._params.get("LongitudinalPersonality", return_default=True),
        icon="speed_limit.png"
      ),
      toggle_item(
        "Enable Lane Departure Warnings",
        DESCRIPTIONS["IsLdwEnabled"],
        self._params.get_bool("IsLdwEnabled"),
        icon="warning.png",
      ),
      toggle_item(
        "Always-On Driver Monitoring",
        DESCRIPTIONS["AlwaysOnDM"],
        self._params.get_bool("AlwaysOnDM"),
        icon="monitoring.png",
      ),
      toggle_item(
        "Record and Upload Driver Camera",
        DESCRIPTIONS["RecordFront"],
        self._params.get_bool("RecordFront"),
        icon="monitoring.png",
      ),
      toggle_item(
        "Record Microphone Audio",
        DESCRIPTIONS["RecordAudio"],
        self._params.get_bool("RecordAudio"),
        icon="microphone.png",
      ),
      toggle_item(
        "Use Metric System", DESCRIPTIONS["IsMetric"], self._params.get_bool("IsMetric"), icon="metric.png"
      ),
      toggle_item(
        "Enable Torque Interceptor",
        DESCRIPTIONS["TorqueInterceptorEnabled"],
        self._params.get_bool("TorqueInterceptorEnabled"),
        icon="chffr_wheel.png",
      )
      toggle_item(
        "Enable Radar Interceptor",
        DESCRIPTIONS["RadarInterceptorEnabled"],
        self._params.get_bool("RadarInterceptorEnabled"),
        icon="chffr_wheel.png",
      ),
      toggle_item(
        "Disable Stock MRCC",
        DESCRIPTIONS["NoMRCC"],
        self._params.get_bool("NoMRCC"),
        icon="chffr_wheel.png",
      ),
      toggle_item(
        "Disable Stock FSC",
        DESCRIPTIONS["NoFSC"],
        self._params.get_bool("NoFSC"),
        icon="chffr_wheel.png",
      ),
      toggle_item(
        "Manual Transmission",
        DESCRIPTIONS["ManualTransmission"],
        self._params.get_bool("ManualTransmission"),
        icon="chffr_wheel.png",
      ),
    ]

    self._scroller = Scroller(items, line_separator=True, spacing=0)

  def _render(self, rect):
    self._scroller.render(rect)

  def _set_longitudinal_personality(self, button_index: int):
    self._params.put("LongitudinalPersonality", button_index)
