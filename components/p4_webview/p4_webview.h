#pragma once

#include "esphome/core/component.h"
#include "esphome/components/display/display.h"

#ifdef USE_TOUCHSCREEN
#include "esphome/components/touchscreen/touchscreen.h"
#endif

namespace esphome {
namespace p4_webview {

class P4WebView : public Component {
 public:
  void set_url(const std::string &url) { this->url_ = url; }
  void set_host(const std::string &host) { this->host_ = host; }
  void set_port(uint16_t port) { this->port_ = port; }
  void set_width(uint16_t width) { this->width_ = width; }
  void set_height(uint16_t height) { this->height_ = height; }
  void set_rotate(uint16_t rotate) { this->rotate_ = rotate; }
  void set_touch_rotate(uint16_t rotate) { this->touch_rotate_ = rotate; }
  void set_kiosk(bool kiosk) { this->kiosk_ = kiosk; }
  void set_token(const std::string &token) { this->token_ = token; }
  void set_stats(bool stats) { this->stats_ = stats; }

  void set_display(display::Display *display) { this->display_ = display; }

#ifdef USE_TOUCHSCREEN
  void set_touchscreen(touchscreen::Touchscreen *touch) { this->touchscreen_ = touch; }
#endif

  void setup() override;
  void loop() override;
  void dump_config() override;
  float get_setup_priority() const override { return setup_priority::AFTER_WIFI; }

 protected:
  std::string url_;
  std::string host_;
  std::string token_;
  uint16_t port_{8123};
  uint16_t width_{800};
  uint16_t height_{1280};
  uint16_t rotate_{0};
  uint16_t touch_rotate_{0};
  bool kiosk_{true};
  bool stats_{true};
  display::Display *display_{nullptr};

#ifdef USE_TOUCHSCREEN
  touchscreen::Touchscreen *touchscreen_{nullptr};
#endif

  bool started_{false};
  uint32_t last_status_ms_{0};
};

}  // namespace p4_webview
}  // namespace esphome
