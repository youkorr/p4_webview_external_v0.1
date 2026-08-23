#include "p4_webview.h"
#include "esphome/core/log.h"

namespace esphome {
namespace p4_webview {

static const char *const TAG = "p4_webview";

void P4WebView::setup() {
  // Deliberately do NOT start a network/browser task here.
  // This keeps the first test safe and gives us a known-good boot point.
  ESP_LOGI(TAG, "Experimental WebView component initialized");
  ESP_LOGI(TAG, "target URL: %s", this->url_.c_str());
  ESP_LOGI(TAG, "kiosk: %s", this->kiosk_ ? "true" : "false");
  this->started_ = true;
}

void P4WebView::loop() {
  // Placeholder for the local HTML engine.
  // The next milestone will attach an HTML parser/renderer here.
  if (!this->started_)
    return;

  const uint32_t now = millis();
  if (now - this->last_status_ms_ > 10000) {
    this->last_status_ms_ = now;
    ESP_LOGD(TAG, "WebView engine placeholder alive; no browser task started");
  }
}

void P4WebView::dump_config() {
  ESP_LOGCONFIG(TAG, "P4 WebView (experimental):");
  ESP_LOGCONFIG(TAG, "  URL: %s", this->url_.c_str());
  ESP_LOGCONFIG(TAG, "  Kiosk: %s", this->kiosk_ ? "true" : "false");
  ESP_LOGCONFIG(TAG, "  Local browser engine: NOT STARTED (safe milestone)");
}

}  // namespace p4_webview
}  // namespace esphome
