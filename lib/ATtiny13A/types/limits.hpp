#ifndef TINYSTD_LIMITS_H
#define TINYSTD_LIMITS_H 1

#include "climits.hpp"
#include "math.hpp"
#include "type_traits.hpp"
namespace tinystd
{

    enum float_round_style
    {
        round_indeterminate = -1, //!< inderteminate rounding type
        round_toward_zero = 0, //!< round to value closer to zero (truncate)
        round_to_nearest = 1, //!< round to nearest value (round)
        round_toward_infinity = 2, //!< round towards positive infinity (ceil)
        round_toward_neg_infinity = 3, //!< round towars negative infinity (floor)
    };

    enum float_denorm_style
    {
        denorm_indeterminate = -1,
        denorm_absent = 0,
        denorm_present = 1
    };

    /**
     * @brief defines a class that has properties about the limitations of certain types
     * 
     * The library defines specializations for the following types:
     * - (signed/unsigned) `char`
     * - (signed/unsigned) `short`
     * - (signed/unsigned) `int`
     * - (signed/unsigned) `long`
     * - (signed/unsigned) `long long`
     * - float
     * - double
     * - long double
     * 
     * with those specializations, types: `intX_t`, `int_fastX_t`, `int_leastX`, `intmax_t`, `intptr_t`, their respective `unsigned` versions 
     * and `ptrdiff_t` are also specialized 
     * 
     * 
     * @tparam T 
     */
    template <class T>
    class numeric_limits
    {
    public:

        //!< defines if this is an specialization or not
        static constexpr bool is_specialized = false; 

        //!< minimum value usable on type
        static constexpr T min() noexcept { return T(); } 

        //!< maximum value usable on type
        static constexpr T max() noexcept { return T(); } 

        //!< lowest possible value
        static constexpr T lowest() noexcept { return T(); } 

        //!< amount of radix digits that can be represented (bitsize - sign bit)
        static constexpr int digits = CHAR_BIT * sizeof(T) - !numeric_limits<T>::is_signed;

        //!< amount of decimal digits that can be displayed
        static constexpr int digits10 = numeric_limits<T>::digits * log10<2>::value;

        //!< amount of numbers necessary to convert to text (used only in floats)
        static constexpr int max_digits10 = 0;

        //!< check if type is signed 
        static constexpr bool is_signed = false;

        //!< check if type is integer
        static constexpr bool is_integer = is_integral_v<T>;

        //!< check if type is exact (for example fractions)
        static constexpr bool is_exact = is_integral_v<T>;

        //!< type representation radix (2 for binary integers)
        static constexpr int radix = 2 * numeric_limits<T>::is_specialized;

        //!< difference between 1 and the next smallest number > 1
        static constexpr T epsilon() noexcept { return T(); }

        //!< rounding error of floating type
        static constexpr T round_error() noexcept { return T(); }

        //!< one more than the smallest negative normalized power
        static constexpr int min_exponent = 0;

        //!< smallest valid normalized power of 10 
        static constexpr int min_exponent10 = 0;

        //!< one more than the biggest positive finite exponent
        static constexpr int max_exponent = 0;

        //!< the largest valid finite power of 10
        static constexpr int max_exponent10 = 0;

        //!< floating point has infinite value
        static constexpr bool has_infinity = !is_integral_v<T>;

        //!< floating point has quiet NaN
        static constexpr bool has_quiet_NaN = !is_integral_v<T>;

        //!< floating point has signaling NaN
        static constexpr bool has_signaling_NaN = !is_integral_v<T>;

        //!< denormalization style for floating points
        static constexpr float_denorm_style has_denorm = denorm_absent;

        //!< detects loss of precision as denormalization loss instead of inexact results
        static constexpr bool has_denorm_loss = false;

        //!< returns infinite for the given floating point type
        static constexpr T infinity() noexcept { return T(); }

        //!< returns a quiet NaN for the given floating point type
        static constexpr T quiet_NaN() noexcept { return T(); }

        //!< returns a signaling NaN for the given floating point type
        static constexpr T signaling_NaN() noexcept { return T(); }

        //!< returns the smallest posirive subnormal value for the given floating point type
        static constexpr T denorm_min() noexcept { return T(); }

        //!< type is IEC559/IEEE754 conforming
        static constexpr bool is_iec559 = false;

        //!< type defines a finite set of values
        static constexpr bool is_bounded = is_integral_v<T>;

        //!< type handles overflows with module arithimetic
        static constexpr bool is_modulo = false;

        //!< type can cause operation traps
        static constexpr bool traps = false;

        //!< type checks for tinyness before rounding
        static constexpr bool tinyness_before = false;

        //!< float rounding modes
        static constexpr float_round_style round_style = round_toward_zero;
    };

    

    /**
     * @brief especialization for the `bool` type
     * 
     */
    template <>
    class numeric_limits<bool>
    {
    public:
        //!< `bool` is specialized
        static constexpr bool is_specialized = true;

        //minimum boolean value: 
        static constexpr bool min() noexcept { return false; }
        static constexpr bool max() noexcept { return true; }
        static constexpr bool lowest() noexcept { return false; }

        static constexpr int digits = 2;

        static constexpr int digits10 = numeric_limits<bool>::digits * log10<2>::value;

        static constexpr int max_digits10 = 0;

        static constexpr bool is_signed = false;

        static constexpr bool is_integer = is_integral<bool>::value;

        static constexpr bool is_exact = is_integral<bool>::value;

        static constexpr int radix = 2 * numeric_limits<bool>::is_specialized;

        static constexpr bool epsilon() noexcept { return false; }

        static constexpr bool round_error() noexcept { return false; }

        static constexpr int min_exponent = 0;

        static constexpr int min_exponent10 = 0;

        static constexpr int max_exponent = 0;

        static constexpr int max_exponent10 = 0;

        static constexpr bool has_infinity = !is_integral<bool>::value;

        static constexpr bool has_quiet_NaN = !is_integral<bool>::value;

        static constexpr bool has_signaling_NaN = !is_integral<bool>::value;

        static constexpr float_denorm_style has_denorm = denorm_absent;

        static constexpr bool has_denorm_loss = false;

        static constexpr bool infinity() noexcept { return false; }

        static constexpr bool quiet_NaN() noexcept { return false; }

        static constexpr bool signaling_NaN() noexcept { return false; }

        static constexpr bool denorm_min() noexcept { return false; }

        static constexpr bool is_iec559 = false;

        static constexpr bool is_bounded = is_integral<bool>::value;

        static constexpr bool is_modulo = false;

        static constexpr bool traps = false;

        static constexpr bool tinyness_before = false;

        static constexpr float_round_style round_style = round_toward_zero;
    };

    template <>
    class numeric_limits<char>
    {
    public:
        static constexpr bool is_specialized = true;

        static constexpr char min() noexcept { return CHAR_MIN; }
        static constexpr char lowest() noexcept { return CHAR_MIN; }
        static constexpr char max() noexcept { return CHAR_MAX; }

        static constexpr bool is_signed = true;
    };

    template <>
    class numeric_limits<signed char>
    {
    public:
        static constexpr bool is_specialized = true;

        static constexpr signed char min() noexcept { return SCHAR_MIN; }
        static constexpr signed char lowest() noexcept { return SCHAR_MIN; }
        static constexpr signed char max() noexcept { return SCHAR_MAX; }

        static constexpr bool is_signed = true;
    };

    template <>
    class numeric_limits<unsigned char>
    {
    public:
        static constexpr bool is_specialized = true;

        static constexpr unsigned char min() noexcept { return 0; }
        static constexpr unsigned char lowest() noexcept { return 0; }
        static constexpr unsigned char max() noexcept { return UCHAR_MAX; }

        static constexpr bool is_signed = false;
    };

    template <>
    class numeric_limits<signed short>
    {
    public:
        static constexpr bool is_specialized = true;

        static constexpr signed short min() noexcept { return SHRT_MIN; }
        static constexpr signed short lowest() noexcept { return SHRT_MIN; }
        static constexpr signed short max() noexcept { return SHRT_MAX; }

        static constexpr bool is_signed = true;
    };

    template <>
    class numeric_limits<unsigned short>
    {
    public:
        static constexpr bool is_specialized = true;

        static constexpr unsigned short min() noexcept { return 0; }
        static constexpr unsigned short lowest() noexcept { return 0; }
        static constexpr unsigned short max() noexcept { return USHRT_MAX; }

        static constexpr bool is_signed = false;
    };

    template <>
    class numeric_limits<signed int> {
    public:
        static constexpr bool is_specialized = true;

        static constexpr signed int min() noexcept { return SINT_MIN; }
        static constexpr signed int lowest() noexcept { return SINT_MIN; }
        static constexpr signed int max() noexcept { return UINT_MAX; }

        static constexpr bool is_signed = true;
    };

    template <>
    class numeric_limits<unsigned int> {
    public:
        static constexpr bool is_specialized = true;

        static constexpr unsigned int min() noexcept { return 0; }
        static constexpr unsigned int lowest() noexcept { return 0; }
        static constexpr unsigned int max() noexcept { return UINT_MAX; }

        static constexpr bool is_signed = false;
    };

    template <>
    class numeric_limits<signed long> : public numeric_limits<signed int> {};

    template <>
    class numeric_limits<unsigned long> : public numeric_limits<unsigned int> {};

    template <>
    class numeric_limits<signed long long> : public numeric_limits<signed int> {};

    template <>
    class numeric_limits<unsigned long long> : public numeric_limits<unsigned int> {};

    template <>
    class numeric_limits<float>;
    template <>
    class numeric_limits<double>;
    template <>
    class numeric_limits<long double>;
} // namespace tinystd

#endif