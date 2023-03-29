#ifndef ATtiny13_math
#define ATtiny13_math 1

namespace attiny
{
    template<typename T = int>
    inline constexpr T abs(const T _value) noexcept {
        return _value < 0 ? -_value : _value;
    }

    template <typename T = int>
    inline constexpr T min(const T a, const T b) noexcept {
        return a < b ? a : b;
    }

    template <typename T = int>
    inline constexpr T max(const T a, const T b) noexcept {
        return a > b ? a : b;
    }

    template<typename T = int>
    inline constexpr T constrain(const T _value, const T _min, const T _max) noexcept {
        return min(max(_value, _min), _max);
    }

    template<typename T = long>
    inline constexpr T map(const T x, const T in_min, const T in_max, const T out_min, const T out_max) noexcept {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }

    template<typename T = int>
    inline constexpr T sq(const T x) {
        return x * x;
    }

    template<typename T = int>
    inline T pow(T base, int exp) {
        if(exp < 0)
            return 1 / pow(base, abs(exp));

        T result = 1;
        while (exp)
        {
            if (exp & 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }

        return result;
    }

    constexpr double pi = 3.1415926535; // literally no one needs more precision to pi as this
    constexpr double pi_2 = 6.283185307;

    template <typename T = float>
    inline T fmod(const T value, const T mod) {
        const auto sign = value < 0;
        T x = abs(value);

        while (x > mod)
            x -= mod;

        return x * (sign ? -1 : 1);
    }

    /* runtime trigonomrety functions, expanded the trigonometric taylor series */
    /* all of them are expanded from 0->3 mainly for the amount of calculations it takes for just one */

    template<typename T = float>
    inline const T sin(const T value) {
        /**
         * evaluating sine function up to n gives
         * 
         * sin(x) = x - x³/3! + x⁵/5! - x⁷/7!
         * 
         *              x³(840 - 42x² + x⁴)
         *        = x - -------------------
         *                     5040
         * 
        */
        const T x = attiny::fmod(value, pi_2);    
        
        return x - attiny::pow(x, 3) * (840 - 42 * attiny::pow(x, 2) + attiny::pow(x, 4)) / 5040 ;
    }


    inline double cos(const double value) {
        /**
         * 
         * evaluating cosine function up to n gives:
         * 
         * cos(x) ≃ 1 - x²/2! + x⁴/4! - x⁶/6!
         * 
         *              x²(360 - 30x² + x⁴)
         *        = 1 - -------------------
         *                      720
        */
        const auto x = fmod(value, pi_2);
        return 1 - pow(x, 2) * (360 - 30 * pow(x, 2) + pow(x, 4)) / 720;
    }

    inline double tan(const double value) {
        /**
         * using tan(x) = sin(x) / cos(x)
         * 
         * on big hopes that gcc will do some compiler magic to reduce this
         */
        return attiny::sin(value) /attiny::cos(value);
    }
    
} // namespace tinystd






#endif