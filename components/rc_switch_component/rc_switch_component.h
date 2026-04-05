#pragma once
#include "esphome.h"

namespace rc_switch_component {

class RCSwitchTransmitter : public Component {
 public:
  void setup() override {}
  void loop() override {}

  void send_code(uint32_t code) {
    // Tu pridáš kód na vysielanie 433MHz
    ESP_LOGD("rc_switch", "Sending code: %u", code);
  }
};

class SendRCSwitchAction : public Action {
 public:
  RCSwitchTransmitter *parent;
  uint32_t code;

  void play(uint32_t play_duration) override {
    if (parent) parent->send_code(code);
  }
};

}  // namespace rc_switch_component
