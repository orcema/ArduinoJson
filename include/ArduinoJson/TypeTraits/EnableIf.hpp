// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#ifndef __ARDUINOJSON_ENABLEIF_HPP
#define __ARDUINOJSON_ENABLEIF_HPP

namespace ArduinoJson {
namespace TypeTraits {

// A meta-function that return the type T if Condition is true.
template <bool Condition, typename T = void>
struct EnableIf {};

template <typename T>
struct EnableIf<true, T> {
  typedef T type;
};
}
}

#endif  // __ARDUINOJSON_ENABLEIF_HPP
