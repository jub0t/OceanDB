#ifndef DB_DATATYPES
#define DB_DATATYPES

#include <cstdint>
#include <string>
#include "./optional_value.cpp"

enum class UniversalTypes: uint16_t {
  STRING,
  NUMBER,
  INTEGER,
  BOOLEAN,
};

union UniversalUnion {
  int64_t int_val;
  // OptionalValue<std::string> str_val;
  float float_val;
  bool bool_val;
};

class UniversalConverter {
  // std::string ToString(UniversalUnion un) {
  //   return static_cast<std::string>(un.str_val.Get());
  // };

  int64_t ToInteger(UniversalUnion un) {
    return static_cast<int64_t>(un.int_val);
  };

  bool ToBoolean(UniversalUnion un) {
    return static_cast<bool>(un.bool_val);
  };
};

#endif
