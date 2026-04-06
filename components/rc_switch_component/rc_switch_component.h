#pragma once

#include "esphome/core/automation.h"
#include "esphome/core/component.h"
#include <RCSwitch.h>

namespace esphome {
namespace rc_switch_component {

template<typename... Ts>
class SendRCSwitchAction : public Action<Ts...> {
 public:
  void set_code(uint32_t code) { code_ = code; }
  void set_gpio(int gpio) { gpio_ = gpio; }

  void play(Ts... x) override {
    RCSwitch sw;
    sw.enableTransmit(gpio_);
    sw.send(code_, 24);
  }

 protected:
  uint32_t code_{0};
  int gpio_{23};
};

}  // namespace rc_switch_component
}  // namespace esphome
