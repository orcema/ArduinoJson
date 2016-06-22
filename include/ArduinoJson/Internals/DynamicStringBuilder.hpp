// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

#include "../String.hpp"

namespace ArduinoJson {
namespace Internals {

// A Print implementation that allows to write in a String
class DynamicStringBuilder {
 public:
  DynamicStringBuilder(String &str) : _str(str) {}

  size_t print(const char *s) {
    size_t prevLength = _str.length();
    _str += s;
    return _str.length() - prevLength;
  }

  size_t print(char c) {
    _str += c;
    return 1;
  }

 private:
  DynamicStringBuilder &operator=(const DynamicStringBuilder &);

  String &_str;
};
}
}
