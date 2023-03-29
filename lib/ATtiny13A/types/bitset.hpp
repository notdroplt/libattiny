#ifndef TINYSTD_BITSET_H
#define TINYSTD_BITSET_H 1

#include <stddef.h>
#include <stdint.h>
#include "type_traits.hpp"
namespace tinystd
{
/**
 * @brief defines _BV macro in case it was not defined already
 * 
 */
#ifndef _BV
#   define _BV(n) (1 << (n))
#endif

    /**
     * @brief bitset class
     * 
     * @tparam N 
     */
    template <size_t N>
    class bitset
    {
    private:
        static_assert(N > 0 && N <= 64, "N needs to be in range of [1, 64]");

        using _bitset_size_t = typename conditional_t<N <= 16, 
            typename conditional_t<N <= 8, uint8_t, uint16_t>::type,
            typename conditional_t<N <= 32, uint32_t, uint64_t>::type
        >::type;
    
        _bitset_size_t _bitset;
    public:
        using SetType = decltype(_bitset);
        constexpr bitset() noexcept {
            this->_bitset = 0;
        }

        explicit constexpr bitset(uint64_t value) noexcept {
            this->_bitset = static_cast<SetType>(value);
        }

        constexpr bool operator[](size_t pos) {
            static_assert(pos < N, "positon needs to be on the interval [0, N)");
            return !!(this->_bitset & _BV(pos));
        }

        constexpr bitset& set(size_t pos, bool value = true) {
            this->_bitset = value ? this->_bitset | _BV(pos) : this->_bitset & (!_BV(pos));
            return *this;
        }

        constexpr size_t size() noexcept {
            return N;
        }

        constexpr bool any() noexcept {
            return !!this->_bitset;
        }

        constexpr bool none() noexcept {
            return !this->_bitset;
        }

        constexpr bool all() noexcept {
            return !~this->_bitset;
        }

        constexpr uint8_t to_uint8() noexcept {
            return static_cast<uint8_t>(this->_bitset);
        }

    };
    
} // namespace tinystd


#endif
