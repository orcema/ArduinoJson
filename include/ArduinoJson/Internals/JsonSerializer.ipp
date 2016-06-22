// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#include "JsonSerializer.hpp"
#include "../JsonArray.hpp"
#include "../JsonArraySubscript.hpp"
#include "../JsonObject.hpp"
#include "../JsonObjectSubscript.hpp"

namespace ArduinoJson {
namespace Internals {
template <typename Writer>
void JsonSerializer<Writer>::serialize(const JsonArray &array) {
  JsonArray::const_iterator it = array.begin();

  if (it == array.end()) {
    return _writer.writeEmptyArray();
  }

  _writer.beginArray();
  for (;;) {
    serialize(*it);
    ++it;
    if (it == array.end()) break;
    _writer.writeComma();
  }
  _writer.endArray();
}

template <typename Writer>
void JsonSerializer<Writer>::serialize(const JsonArraySubscript &variant) {
  serialize(variant.as<JsonVariant>());
}

template <typename Writer>
void JsonSerializer<Writer>::serialize(const JsonObject &object) {
  _writer.beginObject();

  JsonObject::const_iterator it = object.begin();

  while (it != object.end()) {
    _writer.writeString(it->key);
    _writer.writeColon();
    serialize(it->value);

    ++it;
    if (it == object.end()) break;

    _writer.writeComma();
  }

  _writer.endObject();
}

template <typename Writer>
template <typename Key>
void JsonSerializer<Writer>::serialize(
    const JsonObjectSubscript<Key> &variant) {
  serialize(variant.template as<JsonVariant>());
}

template <typename Writer>
void JsonSerializer<Writer>::serialize(const JsonVariant &variant) {
  switch (variant._type) {
    case JSON_UNDEFINED:
      _writer.writeRaw("undefined");
      return;

    case JSON_ARRAY:
      serialize(*variant._content.asArray);
      return;

    case JSON_OBJECT:
      serialize(*variant._content.asObject);
      return;

    case JSON_STRING:
      _writer.writeString(variant._content.asString);
      return;

    case JSON_UNPARSED:
      _writer.writeRaw(variant._content.asString);
      return;

    case JSON_NEGATIVE_INTEGER:
      _writer.writeRaw('-');
    case JSON_POSITIVE_INTEGER:
      _writer.writeInteger(variant._content.asInteger);
      return;

    case JSON_BOOLEAN:
      _writer.writeBoolean(variant._content.asInteger != 0);
      return;

    default:
      uint8_t decimals =
          static_cast<uint8_t>(variant._type - JSON_FLOAT_0_DECIMALS);
      _writer.writeFloat(variant._content.asFloat, decimals);
  }
}
}
}
