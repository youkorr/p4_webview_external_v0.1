#include "p4_webview.h"
#include "esphome/core/log.h"

namespace esphome {
namespace p4_webview {

static const char *const TAG = "p4_webview";

void P4WebView::setup() {
  // Safe milestone: no browser/network task is started yet.
  ESP_LOGI(TAG, "Experimental WebView component initialized");
  ESP_LOGI(TAG, "URL: %s", this->url_.c_str());
  ESP_LOGI(TAG, "Host: %s", this->host_.empty() ? "(not set)" : this->host_.c_str());
  ESP_LOGI(TAG, "Port: %u", this->port_);
  ESP_LOGI(TAG, "Viewport: %ux%u", this->width_, this->height_);
  ESP_LOGI(TAG, "Display rotation: %u degrees", this->rotate_);
  ESP_LOGI(TAG, "Touch rotation: %u degrees", this->touch_rotate_);
  ESP_LOGI(TAG, "Kiosk: %s", this->kiosk_ ? "true" : "false");
  ESP_LOGI(TAG, "Stats: %s", this->stats_ ? "true" : "false");
  ESP_LOGI(TAG, "Token: %s", this->token_.empty() ? "not configured" : "configured");
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
    if (this->stats_)
      ESP_LOGD(TAG, "WebView placeholder alive; engine not started");
  }
}

void P4WebView::dump_config() {
  ESP_LOGCONFIG(TAG, "P4 WebView (experimental):");
  ESP_LOGCONFIG(TAG, "  URL: %s", this->url_.c_str());
  ESP_LOGCONFIG(TAG, "  Host: %s", this->host_.empty() ? "(not set)" : this->host_.c_str());
  ESP_LOGCONFIG(TAG, "  Port: %u", this->port_);
  ESP_LOGCONFIG(TAG, "  Viewport: %ux%u", this->width_, this->height_);
  ESP_LOGCONFIG(TAG, "  Display rotation: %u degrees", this->rotate_);
  ESP_LOGCONFIG(TAG, "  Touch rotation: %u degrees", this->touch_rotate_);
  ESP_LOGCONFIG(TAG, "  Kiosk: %s", this->kiosk_ ? "true" : "false");
  ESP_LOGCONFIG(TAG, "  Stats: %s", this->stats_ ? "true" : "false");
  ESP_LOGCONFIG(TAG, "  Token: %s", this->token_.empty() ? "not configured" : "configured");
  ESP_LOGCONFIG(TAG, "  Local browser engine: NOT STARTED (safe milestone)");
}

}  // namespace p4_webview
}  // namespace esphome
