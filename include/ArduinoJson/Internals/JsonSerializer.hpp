// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

namespace ArduinoJson {
class JsonArray;
class JsonObject;
class JsonVariant;
class JsonArraySubscript;
template <typename TKey>
class JsonObjectSubscript;

namespace Internals {

template <typename Writer>
struct JsonSerializer {
 public:
  JsonSerializer(Writer& writer) : _writer(writer) {}

  void serialize(const JsonArray&);
  void serialize(const JsonArraySubscript&);
  void serialize(const JsonObject&);
  template <typename TKey>
  void serialize(const JsonObjectSubscript<TKey>& variant);
  void serialize(const JsonVariant&);

 private:
  Writer& _writer;
};
}
}
