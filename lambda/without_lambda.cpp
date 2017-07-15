#include <iostream>
#include <algorithm>

void display(int a) {
    std::cout << a << std::endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    std::for_each(arr, arr + sizeof(arr)/sizeof(int), &display);
    std::cout << std::endl;
}