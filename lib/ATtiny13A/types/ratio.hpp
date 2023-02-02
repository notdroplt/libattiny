#ifndef ATtiny_RATIO_H
#define ATtiny_RATIO_H 1

#include <stdint.h>
#include "type_traits.hpp"

namespace tinystd
{
    template <intmax_t Num, intmax_t Den> struct ratio {
        intmax_t num = Num;
        intmax_t den = Den;
    };

    template <typename R1, typename R2>
    using ratio_add = ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den >;

    template <typename R1, typename R2>
    using ratio_subtract = ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den >;

    template <typename R1, typename R2>
    using ratio_multiply = ratio <R1::num * R2::num, R1::den * R2::den>;

    template <typename R1, typename R2>
    using ratio_divide = ratio <R1::num * R2::den, R1::den * R2::num>;

    template <typename R1, typename R2>
    using ratio_is_equal = bool_constant<R1::num == R2::num && R1::den == R2::den>;
    
    template <typename R1, typename R2>
    using ratio_is_not_equal = bool_constant<R1::num != R2::num && R1::den != R2::den>;
} // namespace tinystd



#endif