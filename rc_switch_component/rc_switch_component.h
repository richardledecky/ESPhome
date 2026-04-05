#pragma once
#include "esphome.h"
#include <RCSwitch.h>

namespace esphome {
namespace rc_switch_component {

class RCSwitchTransmitter : public Component {
 public:
  RCSwitch mySwitch;

  void setup() override {
    mySwitch.enableTransmit(4);        // GPIO4 = TX pin
    mySwitch.setProtocol(1);           // Protokol 1
    mySwitch.setPulseLength(345);      // Pulse length
    mySwitch.setRepeatTransmit(10);    // Repeat 10x
  }

  void send_code(unsigned long code) {
    mySwitch.send(code, 24);           // 24-bitový kód
  }
};

class SendRCSwitchAction : public Action<float> {
 public:
  RCSwitchTransmitter *parent;
  unsigned long code;

  void play(float x) override {
    if (parent != nullptr) {
      parent->send_code(code);
    }
  }
};

}  // namespace rc_switch_component
}  // namespace esphome