// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

namespace ArduinoJson {
namespace Internals {

// A dummy Print implementation used in JsonPrintable::measureLength()
class DummyPrint {
 public:
  size_t print(char) {
    return 1;
  }

  size_t print(const char* s) {
    size_t n = 0;
    while (*s++) n++;
    return n;
  }
};
}
}
