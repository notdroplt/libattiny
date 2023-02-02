#ifndef ATtiny_characters
#define ATtiny_characters
#include <types/type_traits.hpp>
#include <ctype.h>

template<typename T>
inline constexpr bool isUpperCase(const T value) {
    static_assert(tinystd::is_integral_v<T>, "expected <T> to be an integer");
    return value >= 'A' && value <= 'Z';
}

template<typename T>
inline constexpr bool isLowerCase(const T value) {
    static_assert(tinystd::is_integral_v<T>, "expected <T> to be an integer");
    return value >= 'a' && value <= 'z';
}

template<typename T>
inline constexpr bool isAlpha(const T value) noexcept {
    static_assert(tinystd::is_integral_v<T>, "expected <T> to be an integer");
	return isUpperCase(value) || isLowerCase(value);
}

template<typename T>
inline constexpr bool isDigit(const T value) noexcept {
    static_assert(tinystd::is_integral_v<T>, "expected <T> to be an integer");
    return value >= '0' && value <= '9';
}

template<typename T>
inline constexpr bool isAlphaNumeric(const T value) noexcept {
    static_assert(tinystd::is_integral_v<T>, "expected <T> to be an integer");
    return isAlpha(value) || isDigit(value);
}

template<typename T>
inline constexpr bool isAscii(const T value) noexcept {
    static_assert(tinystd::is_integral_v<T>, "expected <T> to be an integer");
    return value >= 0 && value <= 255;
}

template<typename T>
inline constexpr bool isControl(const T value) noexcept {
    static_assert(tinystd::is_integral_v<T>, "expected <T> to be an integer");
    return value < 32 || value == 127;
}

template<typename T>
inline constexpr bool isGraph(const T value) noexcept {
    static_assert(tinystd::is_integral_v<T>, "expected <T> to be an integer");
    return !isControl(value);
}

#endif