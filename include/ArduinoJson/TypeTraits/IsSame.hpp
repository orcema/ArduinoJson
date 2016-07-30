// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#ifndef __ARDUINOJSON_ISSAME_HPP
#define __ARDUINOJSON_ISSAME_HPP

namespace ArduinoJson {
namespace TypeTraits {

// A meta-function that returns true if types T and U are the same.
template <typename T, typename U>
struct IsSame {
  static const bool value = false;
};

template <typename T>
struct IsSame<T, T> {
  static const bool value = true;
};
}
}

#endif __ARDUINOJSON_ISSAME_HPP
