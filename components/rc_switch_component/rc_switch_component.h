#pragma once
#include "esphome.h"

namespace rc_switch_component {

class RCSwitchTransmitter : public Component {
 public:
  void setup() override {}
  void loop() override {}
  void send_code(uint32_t code) {
    ESP_LOGD("rc_switch", "Sending code: %u", code);
    // sem príde kód pre vysielanie RF
  }
};

class SendRCSwitchAction : public Action {
 public:
  RCSwitchTransmitter* parent;
  uint32_t code;

  void play(uint32_t) override {
    if (parent != nullptr) {
      parent->send_code(code);
    }
  }
};

}  // namespace rc_switch_component
