import esphome.codegen as cg

rc_switch_ns = cg.esphome_ns.namespace("rc_switch_component")

cg.add_library("rc-switch", None)

cg.add_global(cg.RawExpression("using namespace rc_switch_component;"))

cg.add_source_file("rc_switch_component.cpp")
cg.add_source_file("rc_switch_component.h")
