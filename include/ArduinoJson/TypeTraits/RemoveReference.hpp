// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#ifndef __ARDUINOJSON_REMOVEREFERENCE_HPP
#define __ARDUINOJSON_REMOVEREFERENCE_HPP

namespace ArduinoJson {
namespace TypeTraits {

// A meta-function that return the type T without the reference modifier.
template <typename T>
struct RemoveReference {
  typedef T type;
};
template <typename T>
struct RemoveReference<T&> {
  typedef T type;
};
}
}

#endif  // __ARDUINOJSON_REMOVEREFERENCE_HPP
