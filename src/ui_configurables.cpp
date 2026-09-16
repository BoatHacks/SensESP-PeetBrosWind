#include "ui_configurables.h"

bool FloatConfig::to_json(JsonObject& root) {
  root["value"] = value_;
  return true;
}

bool FloatConfig::from_json(const JsonObject& config) {
  if (!config["value"].is<JsonVariant>()) {
    return false;
  }
  value_ = config["value"];
  return true;
}

// Deliberately typed "string" rather than "number": avoids the browser
// number-input's rounding/step quirks for a filter gain in the 0.0-1.0 range.
const String ConfigSchema(FloatConfig& obj) {
  return R"({"type":"object","properties":{"value":{"title":"value","type":"string"}}})";
}

bool IntConfig::to_json(JsonObject& root) {
  root["value"] = value_;
  return true;
}

bool IntConfig::from_json(const JsonObject& config) {
  if (!config["value"].is<JsonVariant>()) {
    return false;
  }
  value_ = config["value"];
  return true;
}

const String ConfigSchema(IntConfig& obj) {
  return R"({"type":"object","properties":{"value":{"title":"value","type":"integer"}}})";
}

bool CheckboxConfig::to_json(JsonObject& root) {
  root["value"] = value_;
  return true;
}

bool CheckboxConfig::from_json(const JsonObject& config) {
  if (!config["value"].is<JsonVariant>()) {
    return false;
  }
  value_ = config["value"];
  return true;
}

const String ConfigSchema(CheckboxConfig& obj) {
  String schema =
      R"({"type":"object","properties":{"value":{"title":"{{title}}","type":"boolean"}}})";
  schema.replace("{{title}}", obj.get_title());
  return schema;
}
