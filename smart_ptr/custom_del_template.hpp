#pragma once

#include <memory>

template <class T>
struct deleter {
    void operator()(T* p) {
        static_assert(0<sizeof(T), "can't delete an incomplete type");
        std::cout << "destruct pointer" << std::endl;
        delete p;
    }
};

template <class T>
struct deleter<T[]> {
    void operator()(T *p) {
        static_assert( 0 < sizeof(T), "can't delete an incomplete type");
        std::cout << "destruct pointer array" << std::endl;
        delete[] p;
    }
};

template <typename T>
std::shared_ptr<T> make_shared_ptr_array(size_t size) {
    return std::shared_ptr<T>(new T[size], deleter<T[]>());
}

template <class T>
std::shared_ptr<T> make_shared_ptr() {
    return std::shared_ptr<T>(new T(), deleter<T>());
}