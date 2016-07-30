// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#ifndef __ARDUINOJSON_RAWJSON_HPP
#define __ARDUINOJSON_RAWJSON_HPP

namespace ArduinoJson {

// A special type of data that can be used to insert pregenerated JSON portions.
class RawJson {
 public:
  explicit RawJson(const char* str) : _str(str) {}
  operator const char*() const {
    return _str;
  }

 private:
  const char* _str;
};
}

#endif  // __ARDUINOJSON_RAWJSON_HPP
