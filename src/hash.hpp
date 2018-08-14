/** lowlevelzs hash.hpp
    (C) 2018 Erik Zscheile
    License: MIT
 **/
#pragma once
#include <functional>
#include <stdint.h>
// source: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3876.pdf

namespace llzs {
  // needed for hash_val()
  static inline void hash_combine(const std::uintmax_t seed) {}

  extern "C" void llzs_hash_combine(uintmax_t *seed, uintmax_t o) noexcept;

  template<class T>
  static inline void hash_combine(uintmax_t& seed, const T& v) {
    llzs_hash_combine(&seed, std::hash<T>{}(v));
  }

  template<typename T, typename... Types>
  void hash_combine(std::uintmax_t& seed, const T& val, const Types&... args) {
    hash_combine<T>(seed, val);
    hash_combine(seed, args...);
  }

  template<typename... Types>
  size_t hash_val(const Types&... args) {
    uintmax_t seed = 0;
    hash_combine(seed, args...);
    return seed;
  }
}