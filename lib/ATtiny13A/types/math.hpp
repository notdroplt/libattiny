#ifndef TINYSTD_MATH_H
#define TINYSTD_MATH_H 1
#include "cstdint.hpp"
#include "type_traits.hpp"
namespace tinystd
{

    static inline constexpr double pi = 3.141592653589793;

    template <uintmax_t N, uintmax_t R>
    struct log {
        enum {
            value = (N > R - 1) ? (1 + log<N / R, R>::value) : 0
        };
    };

    template <uintmax_t R>
    struct log <0, R> {
        enum {
            value = 0
        };
    };

    template <uintmax_t N>
    struct log2 : log<N, 2> {
        enum {
            value = N > 1 ? 1 + log2<N / 2>::value : 0
        };
    };

    template <uintmax_t N>
    struct log10 : log<N, 10> {
        enum {
            value = N > 9 ? 1 + log2<N / 10>::value : 0
        };
    };


    template <uintmax_t N, uintmax_t E>
    struct pow {
        enum {
            value = N * pow<N, E - 1>::value
        };
    };

    template <uintmax_t N>
    struct pow<N, 0> {
        enum {
            value = 1
        };
    };

    template <uintmax_t N, uintmax_t E>
    static inline constexpr uintmax_t pow_v = pow<N, E>::value;

    template <uintmax_t N>
    struct factorial {
        enum {
            value = N * factorial<N - 1>::value
        };
    };

    template <>
    struct factorial<0> {
        enum {
            value = 1
        };
    };

    template <uintmax_t N>
    static inline constexpr uintmax_t factorial_v = factorial<N>::value;

} // namespace tinystd


#endif