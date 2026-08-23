#include "p4_webview.h"
#include "esphome/core/log.h"

namespace esphome {
namespace p4_webview {

static const char *const TAG = "p4_webview";

void P4WebView::setup() {
  // Milestone 1: initialize the component only. The actual browser engine
  // is intentionally not started until its P4 rendering backend is ready.
  ESP_LOGI(TAG, "P4 WebView initialized");
  ESP_LOGI(TAG, "URL: %s", this->url_.c_str());
  ESP_LOGI(TAG, "Host: %s", this->host_.empty() ? "(not set)" : this->host_.c_str());
  ESP_LOGI(TAG, "Port: %u", this->port_);
  ESP_LOGI(TAG, "Viewport: %ux%u", this->width_, this->height_);
  ESP_LOGI(TAG, "Display rotation: %u degrees", this->rotate_);
  ESP_LOGI(TAG, "Touch rotation: %u degrees", this->touch_rotate_);
  ESP_LOGI(TAG, "Kiosk: %s", this->kiosk_ ? "true" : "false");
  ESP_LOGI(TAG, "Stats: %s", this->stats_ ? "true" : "false");
  // Never print the token itself. It is a credential.
  ESP_LOGI(TAG, "HA token: %s", this->token_.empty() ? "not configured" : "configured");

  if (this->rotate_ != 0 && this->rotate_ != 90 && this->rotate_ != 180 && this->rotate_ != 270) {
    ESP_LOGE(TAG, "Invalid display rotation: %u", this->rotate_);
    this->mark_failed();
    return;
  }
  if (this->touch_rotate_ != 0 && this->touch_rotate_ != 90 && this->touch_rotate_ != 180 &&
      this->touch_rotate_ != 270) {
    ESP_LOGE(TAG, "Invalid touch rotation: %u", this->touch_rotate_);
    this->mark_failed();
    return;
  }

  this->started_ = true;
}

void P4WebView::loop() {
  if (!this->started_)
    return;

  // Keep this task deliberately idle in the bootstrap build. The next
  // milestone will attach the P4-native HTML renderer here.
  if (!this->stats_)
    return;

  const uint32_t now = millis();
  if (now - this->last_status_ms_ >= 10000) {
    this->last_status_ms_ = now;
    ESP_LOGD(TAG, "WebView runtime ready; renderer backend not attached yet");
  }
}

void P4WebView::dump_config() {
  ESP_LOGCONFIG(TAG, "P4 WebView:");
  ESP_LOGCONFIG(TAG, "  URL: %s", this->url_.c_str());
  ESP_LOGCONFIG(TAG, "  Host: %s", this->host_.empty() ? "(not set)" : this->host_.c_str());
  ESP_LOGCONFIG(TAG, "  Port: %u", this->port_);
  ESP_LOGCONFIG(TAG, "  Viewport: %ux%u", this->width_, this->height_);
  ESP_LOGCONFIG(TAG, "  Display rotation: %u degrees", this->rotate_);
  ESP_LOGCONFIG(TAG, "  Touch rotation: %u degrees", this->touch_rotate_);
  ESP_LOGCONFIG(TAG, "  Kiosk: %s", this->kiosk_ ? "true" : "false");
  ESP_LOGCONFIG(TAG, "  Stats: %s", this->stats_ ? "true" : "false");
  ESP_LOGCONFIG(TAG, "  HA token: %s", this->token_.empty() ? "not configured" : "configured");
  ESP_LOGCONFIG(TAG, "  Renderer: bootstrap / not attached");
}

}  // namespace p4_webview
}  // namespace esphome
