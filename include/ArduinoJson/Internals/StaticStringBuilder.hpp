// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

namespace ArduinoJson {
namespace Internals {

// A Print implementation that allows to write in a char[]
class StaticStringBuilder {
 public:
  StaticStringBuilder(char *buf, size_t size)
      : _buffer(buf), _capacity(size - 1), _length(0) {
    _buffer[0] = '\0';
  }

  size_t print(char c) {
    if (_length >= _capacity) return 0;

    _buffer[_length++] = c;
    _buffer[_length] = '\0';
    return 1;
  }

  size_t print(const char *s) {
    size_t prevLength = _length;
    while (_length < _capacity && *s) {
      _buffer[_length++] = *s++;
    }
    _buffer[_length] = '\0';
    return _length - prevLength;
  }

 private:
  char *_buffer;
  size_t _capacity;
  size_t _length;
};
}
}
