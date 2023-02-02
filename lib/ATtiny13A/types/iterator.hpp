#include "type_traits.hpp"
#include "cstdint.hpp"

namespace tinystd
{
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&, class raw = void>
    struct iterator {
        using difference_type = Distance;
        using value_type = T;
        using pointer = Pointer;
        using reference = Reference;
        using iterator_category = Category;
    };


    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct foward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public foward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag{};
    struct contiguous_iterator_tag : public random_access_iterator_tag {};
    
    template <class T>
    struct iterator<contiguous_iterator_tag, remove_cv_t<T>, ptrdiff_t, T*, T&, typename is_pointer<T>::type> {};

    template <class T>
    struct iterator<random_access_iterator_tag, const T, const T*, const T&, typename is_pointer<const T>::type> {};

    template <class T>
    struct input_iterator : public iterator<input_iterator_tag, T>
    {
        /* data */
    };
    
} // namespace tinystd
