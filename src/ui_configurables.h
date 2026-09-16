#ifndef UI_CONFIGURABLES_H_
#define UI_CONFIGURABLES_H_

#include "sensesp.h"
#include "sensesp/system/saveable.h"
#include "sensesp/ui/config_item.h"

using namespace sensesp;

/**
 * @brief Configurable for a single float value.
 *
 */
class FloatConfig : public FileSystemSaveable {
 public:
  FloatConfig(float value, const String& config_path)
      : FileSystemSaveable(config_path), value_(value) {
    load();
  }

  virtual bool to_json(JsonObject& root) override;
  virtual bool from_json(const JsonObject& config) override;

  float get_value() { return value_; }

 protected:
  float value_ = 0.0;
};

const String ConfigSchema(FloatConfig& obj);

/**
 * @brief Configurable for a single int value.
 *
 */
class IntConfig : public FileSystemSaveable {
 public:
  IntConfig(int value, const String& config_path)
      : FileSystemSaveable(config_path), value_(value) {
    load();
  }

  virtual bool to_json(JsonObject& root) override;
  virtual bool from_json(const JsonObject& config) override;

  int get_value() { return value_; }

 protected:
  int value_ = 0;
};

const String ConfigSchema(IntConfig& obj);

/**
 * @brief Configurable for a single boolean value, represented as a checkbox
 *
 */
class CheckboxConfig : public FileSystemSaveable {
 public:
  CheckboxConfig(bool value, const String& title, const String& config_path)
      : FileSystemSaveable(config_path), value_(value), title_(title) {
    load();
  }

  virtual bool to_json(JsonObject& root) override;
  virtual bool from_json(const JsonObject& config) override;

  bool get_value() { return value_; }
  const String& get_title() { return title_; }

 protected:
  bool value_ = false;
  String title_ = "Enable";
};

const String ConfigSchema(CheckboxConfig& obj);

#endif  // UI_CONFIGURABLES_H_
