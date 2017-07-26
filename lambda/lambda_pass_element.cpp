#include <iostream>
#include <algorithm>

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };

    int mul = 5;

    std::for_each(arr, arr + sizeof(arr)/sizeof(int), [&](int x) {
        std::cout << x << " ";
        mul = 3;
    });

    std::cout << std::endl;

    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [=](int &x) {
        x = x*mul;
    });

    std::cout << std::endl;

    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [](int x) {
        std::cout << x << " ";
    });
    
    std::cout << std::endl;

}