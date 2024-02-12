#ifndef OCEAN_OPTIONAL_VALUE
#define OCEAN_OPTIONAL_VALUE

#include <iostream>

template<typename T>
struct OptionalValue {
public:
    constexpr OptionalValue() : has_value_(false), value_() {}
    
    constexpr OptionalValue(T&& val) : has_value_(true), value_(std::move(val)) {}
    
    constexpr explicit operator bool() const { return has_value_; }
    
    T Get() { return this->value_; };
    // Provide other utility functions for checking presence, getting, etc., as needed
private:
    bool has_value_;
    T value_;
};

// Specialize template for booleans since 'explicit operator bool' cannot be used on built-in types
template<>
struct OptionalValue<bool> {
public:
    constexpr OptionalValue() : has_value_(false), value_(false) {}
    
    constexpr OptionalValue(bool val) : has_value_(true), value_(val) {}
    
    constexpr explicit operator bool() const { return has_value_; }
    
    // Provide other utility functions for checking presence, getting, etc., as needed
private:
    bool has_value_;
    bool value_;
};

#endif // !OCEAN_OPTIONAL_VALUE

