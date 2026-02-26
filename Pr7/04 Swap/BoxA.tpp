#pragma once
#pragma once

template<typename T>
BoxA<T>::BoxA(T v) : value_(v) {}

template<typename T>
void BoxA<T>::print() const {
    std::cout << "BoxA: " << value_ << "\n";
}