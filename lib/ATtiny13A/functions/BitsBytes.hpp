#ifndef BITS_AND_BYTES
#define BITS_AND_BYTES 1

#include <avr/sfr_defs.h>

template <typename T = int>
inline constexpr T bit(const T n) noexcept {
	return _BV(n);
}

template <typename T = int>
inline constexpr T bitClear(const T x, const T n) noexcept {
	return x & ~_BV(n);
}

template <typename T = int>
inline constexpr T bitRead(const T x, const T n) noexcept {
	return !!(x & _BV(n));
}

template <typename T = int>
inline constexpr T bitSet(const T x, const T n) noexcept {
	return x | _BV(n);
}

template <typename T = int>
inline constexpr T bitWrite(const T x, const T n, const bool b) noexcept {
	return x | (b ? _BV(n) : 0);
}

template <typename T = int>
inline constexpr T highByte(const T x) {
	return x >> (sizeof(T) * 8 - 8);
}

template <typename T = int>
inline constexpr T lowByte(const T x) {
	return x & 0xff;
}

#endif 