#pragma once

#include "esphome/core/component.h"
#include "esphome/components/display/display_buffer.h"

#ifdef USE_TOUCHSCREEN
#include "esphome/components/touchscreen/touchscreen.h"
#endif

namespace esphome {
namespace p4_webview {

/*
 * Safe first milestone:
 * - owns no USB resources
 * - does not replace the display driver
 * - does not start a browser during boot
 * - provides a stable integration point for the future HTML engine.
 */
class P4WebView : public Component {
 public:
  void set_url(const std::string &url) { this->url_ = url; }
  void set_kiosk(bool kiosk) { this->kiosk_ = kiosk; }

  void set_display(display::DisplayBuffer *display) { this->display_ = display; }

#ifdef USE_TOUCHSCREEN
  void set_touchscreen(touchscreen::Touchscreen *touch) { this->touchscreen_ = touch; }
#endif

  void setup() override;
  void loop() override;
  void dump_config() override;
  float get_setup_priority() const override { return setup_priority::AFTER_WIFI; }

 protected:
  std::string url_;
  bool kiosk_{true};
  display::DisplayBuffer *display_{nullptr};

#ifdef USE_TOUCHSCREEN
  touchscreen::Touchscreen *touchscreen_{nullptr};
#endif

  bool started_{false};
  uint32_t last_status_ms_{0};
};

}  // namespace p4_webview
}  // namespace esphome
