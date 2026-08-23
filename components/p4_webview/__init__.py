import esphome.config_validation as cv
import esphome.codegen as cg
from esphome.const import CONF_ID
from esphome.components import display, touchscreen

DEPENDENCIES = ["display"]

p4_webview_ns = cg.esphome_ns.namespace("p4_webview")
P4WebView = p4_webview_ns.class_("P4WebView", cg.Component)

CONF_URL = "url"
CONF_HOST = "host"
CONF_PORT = "port"
CONF_WIDTH = "width"
CONF_HEIGHT = "height"
CONF_ROTATE = "rotate"
CONF_TOUCH_ROTATE = "touch_rotate"
CONF_KIOSK = "kiosk"
CONF_TOKEN = "token"
CONF_STATS = "stats"
CONF_DISPLAY_ID = "display_id"
CONF_TOUCHSCREEN_ID = "touchscreen_id"

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(P4WebView),
    cv.Required(CONF_URL): cv.string,
    cv.Optional(CONF_HOST, default=""): cv.string,
    cv.Optional(CONF_PORT, default=8123): cv.port,
    cv.Optional(CONF_WIDTH, default=800): cv.positive_int,
    cv.Optional(CONF_HEIGHT, default=1280): cv.positive_int,
    cv.Optional(CONF_ROTATE, default=0): cv.one_of(0, 90, 180, 270, int=True),
    cv.Optional(CONF_TOUCH_ROTATE, default=0): cv.one_of(0, 90, 180, 270, int=True),
    cv.Optional(CONF_KIOSK, default=True): cv.boolean,
    cv.Optional(CONF_TOKEN, default=""): cv.string,
    cv.Optional(CONF_STATS, default=True): cv.boolean,
    cv.Required(CONF_DISPLAY_ID): cv.use_id(display.Display),
    cv.Optional(CONF_TOUCHSCREEN_ID): cv.use_id(touchscreen.Touchscreen),
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    cg.add(var.set_url(config[CONF_URL]))
    cg.add(var.set_host(config[CONF_HOST]))
    cg.add(var.set_port(config[CONF_PORT]))
    cg.add(var.set_width(config[CONF_WIDTH]))
    cg.add(var.set_height(config[CONF_HEIGHT]))
    cg.add(var.set_rotate(config[CONF_ROTATE]))
    cg.add(var.set_touch_rotate(config[CONF_TOUCH_ROTATE]))
    cg.add(var.set_kiosk(config[CONF_KIOSK]))
    cg.add(var.set_token(config[CONF_TOKEN]))
    cg.add(var.set_stats(config[CONF_STATS]))
    display_var = await cg.get_variable(config[CONF_DISPLAY_ID])
    cg.add(var.set_display(display_var))
    if CONF_TOUCHSCREEN_ID in config:
        touch_var = await cg.get_variable(config[CONF_TOUCHSCREEN_ID])
        cg.add(var.set_touchscreen(touch_var))
