#include <memory>
#include <functional>
#include <iostream>
#include <algorithm>

int arr[10] = { 1, 20, 13, 4, 5, 6, 10, 28, 19, 15 };

int add(int first, int second, int third) {
    return first + second + third;
}

bool division(int num, int den) {
    if (num % den == 0) {
        return true;
    } else {
        return false;
    }
}

int approach_1() {
    int count = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i ++) {
        if (division(arr[i], 5)) {
            count ++;
        }
    }
    return count;
}

int approach_2() {
    return std::count_if(arr, arr + sizeof(arr)/sizeof(arr[0]), std::bind(&division, std::placeholders::_1, 5));
}

int main(int argc, char* argv[]) {
    int x = add(4, 5, 6);
    auto new_add_func = std::bind(&add, 12, std::placeholders::_1, std::placeholders::_2);
    int y = new_add_func(5, 6);
    std::cout << "y :" << y << std::endl;

    auto mode_add_func = std::bind(&add, 1, std::placeholders::_1, std::placeholders::_2);
    int z = mode_add_func(3, 4);
    std::cout << "z: " << z << std::endl;

    std::function<int(int)> mode_add_funcObj = std::bind(&add, std::placeholders::_1, 20, 30);
    int v = mode_add_funcObj(4);
    std::cout << "v: " << v << std::endl;

    std::cout << "approach1: " << approach_1() << std::endl;
    std::cout << "approach2: " << approach_2() << std::endl;
}