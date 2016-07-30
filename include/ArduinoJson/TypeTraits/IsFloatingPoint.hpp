// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#ifndef __ARDUINOJSON_ISFLOATINGPOINT_HPP
#define __ARDUINOJSON_ISFLOATINGPOINT_HPP

#include "IsSame.hpp"

namespace ArduinoJson {
namespace TypeTraits {

// A meta-function that returns true if T is a floating point type
template <typename T>
struct IsFloatingPoint {
  static const bool value = IsSame<T, float>::value || IsSame<T, double>::value;
};
}
}

#endif  // __ARDUINOJSON_ISFLOATINGPOINT_HPP
