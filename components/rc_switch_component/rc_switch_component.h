#pragma once

#include "esphome/core/component.h"
#include "esphome/core/automation.h"
#include "esphome/core/log.h"
#include <RCSwitch.h>

namespace esphome {
namespace rc_switch_component {

class RCSwitchTransmitter : public Component {
 public:
  RCSwitchTransmitter() = default;

  void setup() override {
    ESP_LOGI("rc_switch", "Initializing RC Switch transmitter");
    transmitter_.enableTransmit(12);  // default TX pin (GPIO12)
  }

  void send_code(uint32_t code) {
    ESP_LOGI("rc_switch", "Sending RC code: %u", code);
    transmitter_.send(code, 24);
  }

 protected:
  RCSwitch transmitter_;
};

class SendRCSwitchAction : public Action<void> {
 public:
  RCSwitchTransmitter *parent;
  uint32_t code;

  void play(Ts... x) override {
    if (parent != nullptr) {
      parent->send_code(code);
    }
  }
};

}  // namespace rc_switch_component
}  // namespace esphome
