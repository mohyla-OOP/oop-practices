#pragma once
// STRUCT TEMPLATE remove_reference
template <class _Ty>
struct remove_reference {
    using type = _Ty;
};

template <class _Ty>
struct remove_reference<_Ty&> {
    using type = _Ty;
};
template <class _Ty>
struct remove_reference<_Ty&&> {
    using type = _Ty;
};

template <class _Ty>
using remove_reference_t = typename remove_reference<_Ty>::type;

template <typename T>
struct wrap {};

template <typename T>
void show_type(T&& p) {
    std::cout << typeid(wrap<decltype(p)>).name() << std::endl;
}

// FUNCTION TEMPLATE move
template <class _Ty>
_NODISCARD constexpr remove_reference_t<_Ty>&& move(_Ty&& _Arg) noexcept { // forward _Arg as movable
    std::cout << typeid(_Arg).name() << std::endl;
    std::cout << std::boolalpha << std::is_lvalue_reference<_Ty>::value << std::endl;
    show_type(_Arg);
    return static_cast<remove_reference_t<_Ty>&&>(_Arg);
}

