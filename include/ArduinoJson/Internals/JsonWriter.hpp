// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

#include "TextWriter.hpp"

namespace ArduinoJson {
namespace Internals {

template <typename Print>
class JsonWriter : public TextWriter<Print> {
 public:
  explicit JsonWriter(Print &sink) : TextWriter<Print>(sink) {}

  void beginArray() {
    this->writeRaw('[');
  }
  void endArray() {
    this->writeRaw(']');
  }
  void writeEmptyArray() {
    this->writeRaw("[]");
  }

  void beginObject() {
    this->writeRaw('{');
  }
  void endObject() {
    this->writeRaw('}');
  }
  void writeEmptyObject() {
    this->writeRaw("{}");
  }

  void writeColon() {
    this->writeRaw(':');
  }
  void writeComma() {
    this->writeRaw(',');
  }
};
}
}
