#include "p4_webview.h"
#include "esphome/core/log.h"

namespace esphome {
namespace p4_webview {

static const char *const TAG = "p4_webview";

void P4WebView::setup() {
  // Safe milestone: no browser/network task is started yet.
  ESP_LOGI(TAG, "Experimental WebView component initialized");
  ESP_LOGI(TAG, "target URL: %s", this->url_.c_str());
  ESP_LOGI(TAG, "kiosk: %s", this->kiosk_ ? "true" : "false");
  ESP_LOGI(TAG, "rotation: %u degrees", this->rotation_);
  this->started_ = true;
}

void P4WebView::loop() {
  // Placeholder for the future local HTML engine.
  // No browser task is started in this milestone.
  if (!this->started_)
    return;

  const uint32_t now = millis();
  if (now - this->last_status_ms_ > 10000) {
    this->last_status_ms_ = now;
    ESP_LOGD(TAG, "WebView placeholder alive; engine not started");
  }
}

void P4WebView::dump_config() {
  ESP_LOGCONFIG(TAG, "P4 WebView (experimental):");
  ESP_LOGCONFIG(TAG, "  URL: %s", this->url_.c_str());
  ESP_LOGCONFIG(TAG, "  Kiosk: %s", this->kiosk_ ? "true" : "false");
  ESP_LOGCONFIG(TAG, "  Rotation: %u degrees", this->rotation_);
  ESP_LOGCONFIG(TAG, "  Local browser engine: NOT STARTED (safe milestone)");
}

}  // namespace p4_webview
}  // namespace esphome
