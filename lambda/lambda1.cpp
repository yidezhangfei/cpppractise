#include <iostream>
#include <algorithm>

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    std::for_each(arr, arr+sizeof(arr)/sizeof(int), [](int x) { 
        std::cout << x << std::endl;
    });
}