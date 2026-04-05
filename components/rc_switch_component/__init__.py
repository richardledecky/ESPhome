import esphome.codegen as cg
import esphome.config_validation as cv

CODEOWNERS = ["@richardledecky"]
DEPENDENCIES = []
AUTO_LOAD = []

ns = cg.esphome_ns.namespace("rc_switch_component")

RCSwitchTransmitter = ns.class_("RCSwitchTransmitter", cg.Component)
SendRCSwitchAction = ns.class_("SendRCSwitchAction", cg.Action)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(RCSwitchTransmitter),
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[cv.GenerateID()])
    await cg.register_component(var, config)
