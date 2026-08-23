# p4_webview — ESPHome experimental WebView

Experimental first-stage external component for ESP32-P4 / ESPHome.

## Important

This is **not yet a full browser**. This first milestone is deliberately safe:
- no TinyUSB dependency
- no Chromium
- no Linux
- no changes to the ESPHome boot path
- exposes a `p4_webview` component and a test page/status
- keeps the display/touch integration as the next layer

The long-term target is a local HTML/CSS/JS engine on ESP32-P4, with Home Assistant loaded directly by the P4.

## External component

```yaml
external_components:
  - source:
      type: git
      url: https://github.com/YOUR_USER/p4-webview
      ref: main
    components: [p4_webview]
    refresh: 0s
```

## Test

Use `p4_webview_test.yaml`.

The test deliberately uses a local, non-network URL first. Do not replace the existing working firmware until this compiles and boots.
