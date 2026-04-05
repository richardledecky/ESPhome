import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import pins

CODEOWNERS = ["@richardledecky"]
DEPENDENCIES = []
AUTO_LOAD = []

# Namespace
ns = cg.esphome_ns.namespace("rc_switch_component")
RCSwitchComponent = ns.class_("RCSwitchComponent", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(RCSwitchComponent),
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[cv.GenerateID()])
    await cg.register_component(var, config)
