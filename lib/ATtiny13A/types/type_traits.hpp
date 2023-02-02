/* ATtiny type_traits rewrite. droplt 2022*/
#ifndef ATtiny_type_traits
#define ATtiny_type_traits 1

#include <stddef.h>

namespace tinystd {

	/**
	 * @brief integral constant, the base of type_traits
	 * 
	 * this struct works such that integers can be used as types
	 * 
	 *
	 * @tparam T any integral type
	 * @tparam v any value for that integral
	 */
	template<class T, T v>
	struct integral_constant {
		using value_type = T; 
		using type = integral_constant; //!< using injected-class-name

		static constexpr T value = v; //!< defines a member for the value-type
		constexpr operator value_type() const noexcept { return value; }
		constexpr value_type operator()() const noexcept { return value; } // C++14 
	};

	/* especialization of integral_constant for boolean types */
	template<bool B> using bool_constant = integral_constant<bool, B>;

	
	using true_type = bool_constant<true>;
	using false_type = bool_constant<false>;

	
	template<class T> struct type_identity { using type = T; };
	template<class T, class U> struct is_same : false_type {};
	template<class T> struct is_same<T, T> : true_type {};

	template<class T, class U>
	inline constexpr bool is_same_v = is_same<T, U>::value;
	
	/* remove qualifiers group */
	template<class T> struct remove_const					{ using type = T; };
	template<class T> struct remove_const<const T>			{ using type = T; };

	template<class T> using remove_const_t = typename remove_const<T>::type;

	template<class T> struct remove_volatile				{ using type = T; };
	template<class T> struct remove_volatile<volatile T>	{ using type = T; };

	template<class T> using remove_volatile_t = typename remove_volatile<T>::type;

	template<class T> struct remove_cv						{ using type = T; };
	template<class T> struct remove_cv<const T>				{ using type = T; };
	template<class T> struct remove_cv<volatile T>			{ using type = T; };
	template<class T> struct remove_cv<const volatile T>	{ using type = T; };

	template<class T> using remove_cv_t  = typename remove_cv<T>::type;

	template<class T> struct remove_reference      { using type = T; };
	template<class T> struct remove_reference<T&>  { using type = T; };
	template<class T> struct remove_reference<T&&> { using type = T; };

	template<class T> using remove_reference_t = typename remove_reference<T>::type; 

	template< class T > struct remove_pointer                    { using type = T; };
	template< class T > struct remove_pointer<T*>                { using type = T; };
	template< class T > struct remove_pointer<T* const>          { using type = T; };
	template< class T > struct remove_pointer<T* volatile>       { using type = T; };
	template< class T > struct remove_pointer<T* const volatile> { using type = T; };

	template<class T> using remove_pointer_t = typename remove_pointer<T>::type;

	/* add qualifiers group */
	namespace detail{ 
		template <class T> auto try_add_lvalue_reference(int) -> type_identity<T&>;
		template <class T> auto try_add_lvalue_reference(...) -> type_identity<T>;
	
		template <class T> auto try_add_rvalue_reference(int) -> type_identity<T&&>;
		template <class T> auto try_add_rvalue_reference(...) -> type_identity<T>;
		
		template <class T> auto try_add_pointer(int) -> type_identity<typename remove_reference<T>::type*>;
		template <class T> auto try_add_pointer(...) -> type_identity<T>;


	} // namespace detail
	
	template <class T> struct add_pointer : decltype(detail::try_add_pointer<T>(0)) {};
	
	template <class T> struct add_lvalue_reference : decltype(detail::try_add_lvalue_reference<T>(0)) {};
	template <class T> struct add_rvalue_reference : decltype(detail::try_add_rvalue_reference<T>(0)) {};


	template<class T> struct add_cv { using type = const volatile T; };
	template<class T> struct add_const { using type = const T; };
	template<class T> struct add_volatile { using type = volatile T; };

	/* is type group */

	template<class T> using is_void = is_same<void, typename remove_cv<T>::type>;
	template<class T> using is_null_pointer = is_same<nullptr_t, typename remove_cv<T>::type>;

	template<class T> struct is_integral : false_type {};
	template<class T> struct is_integral<const T> :				is_integral<typename remove_cv<T>::type> {};
	template<class T> struct is_integral<volatile T> :			is_integral<typename remove_cv<T>::type> {};
	template<class T> struct is_integral<const volatile T> : 	is_integral<typename remove_cv<T>::type> {};
	template<> struct is_integral<unsigned char> : 	true_type {};
	template<> struct is_integral<unsigned short> :	true_type {};
	template<> struct is_integral<unsigned int> :	true_type {};
	template<> struct is_integral<unsigned long> :	true_type {};
	template<> struct is_integral<signed char> :	true_type {};
	template<> struct is_integral<signed short> :	true_type {};
	template<> struct is_integral<signed int> :		true_type {};
	template<> struct is_integral<signed long> :	true_type {};
	template<> struct is_integral<char> : 			true_type {};
	template<> struct is_integral<bool> : 			true_type {};

	template<class T>
	bool is_integral_v = is_integral<T>::value;

	template<class T> using is_floating_point = bool_constant<
		is_same<float, typename remove_cv<T>::type>::value  ||
		is_same<double, typename remove_cv<T>::type>::value  ||
		is_same<long double, typename remove_cv<T>::type>::value
	> ;

	template<class T> struct is_array : false_type {};    
	template<class T> struct is_array<T[]> : true_type {};    
	template<class T, size_t N> struct is_array<T[N]> : true_type {};

	template<class T> struct is_enum : bool_constant<__is_enum(T)> {};
	template<typename T> struct is_union : bool_constant<__is_union(T)> {};

	
	namespace detail {
		template <class T> bool_constant<!is_union<T>::value> test(int T::*);
		template <class> false_type test(...);
	}
	
	template <class T> struct is_class : decltype(detail::test<T>(nullptr)) {};


	template<class T> struct is_const;
	template<class T> struct is_reference;
	template<class T> struct is_function : bool_constant<!is_const<const T>::value && !is_reference<T>::value> {};


	template<class T> struct is_pointer : false_type {};    
	template<class T> struct is_pointer<T*> : true_type {};    
	template<class T> struct is_pointer<T* const> : true_type {};    
	template<class T> struct is_pointer<T* volatile> : true_type {};
	template<class T> struct is_pointer<T* const volatile> : true_type {};

	template<class T> 
	constexpr bool is_pointer_v = is_pointer<T>::value;

	template<class T> struct is_member_pointer_helper : false_type {};
	template<class T, class U> struct is_member_pointer_helper<T U::*> : true_type {};
	template<class T> struct is_member_pointer : is_member_pointer_helper<typename remove_cv<T>::type> {};

	// template<class T> struct is_member_function_pointer_helper : false_type {};
	// template<class T, class U> struct is_member_function_pointer_helper<T U::*> : is_function<T> {};
	// template<class T> struct is_member_function_pointer : is_member_function_pointer_helper<typename remove_cv<T>::type> {};
	// template<class T> struct is_member_object_pointer : bool_constant<is_member_pointer<T>::value && !is_member_function_pointer<T>::value> {};

	template<class T> struct is_lvalue_reference     : false_type {};
	template<class T> struct is_lvalue_reference<T&> : true_type {};

	template<class T> struct is_rvalue_reference      : false_type {};
	template<class T> struct is_rvalue_reference<T&&> : true_type {};


	template<class T> struct is_arithmetic : bool_constant<is_integral<T>::value || is_floating_point<T>::value> {};
	template<class T> struct is_fundamental : bool_constant<is_arithmetic<T>::value || is_void<T>::value  || is_null_pointer<T>::value> {};
	template<class T> struct is_scalar : integral_constant<bool,
						is_arithmetic<T>::value     ||
						is_enum<T>::value           ||
						is_pointer<T>::value        ||
						is_member_pointer<T>::value ||
						is_null_pointer<T>::value> {};

	template<class T> using is_compound = bool_constant<!is_fundamental<T>::value>;

	template <class T> struct is_reference      : false_type {};
	template <class T> struct is_reference<T&>  : true_type {};
	template <class T> struct is_reference<T&&> : true_type {};
	
	/* is qualifier group */
	template<class T> struct is_const			: false_type {};
	template<class T> struct is_const<const T>	: true_type {};

	template<class T> struct is_volatile				: false_type {};
	template<class T> struct is_volatile<volatile T>	: true_type {};

	template<class T> using is_trivial = bool_constant<__is_trivial(T)>;
	template<class T> using is_trivially_copyable = bool_constant<__is_trivially_copyable(T)>;
	template<class T> using is_trivially_constructible = bool_constant<__is_trivially_constructible(T)>;
	template<class T> using is_standard_layout = bool_constant<__is_standard_layout(T)>;
	template<class T> using is_pod = bool_constant<__is_pod(T)>;


	/* conditional types */

	template<bool B, class T, class F> struct conditional_t { using type = T; };
	template<class T, class F> struct conditional_t<false, T, F> { using type = F; };
	
	template<class...> struct conjunction_t : true_type {};
	template<class B1> struct conjunction_t<B1> : B1 {};
	template<class B1, class... Bn> struct conjunction_t<B1, Bn...> : conditional_t<bool(B1::value), conjunction_t<Bn...>, B1> {};

	template<class B1, class... Bn> using cond_and = conjunction_t<B1, Bn...>;

	template<class...> struct disjunction_t : false_type {};
	template<class B1> struct disjunction_t<B1> : B1 {};
	template<class B1, class... Bn> struct disjunction_t<B1, Bn...> : conditional_t<bool(B1::value), B1, disjunction_t<Bn...>>  { };

	template<class B1, class... Bn> using cond_or = disjunction_t<B1, Bn...>;

	template<class B> using cond_not = bool_constant<!bool(B::value)> ;


	/* conditional compiling */

	template<bool B, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { using type = T; };

	
} // namespace Types


#endif 
