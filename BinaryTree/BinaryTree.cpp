#include "BinaryTree.hpp"

int main() {
    int a[] = { 1, 2, 3, '#', 6, 7, '#', 9, 10, '#'};
    BinaryTree<int>* bt = new BinaryTree<int>(a, 10, '#');
}
