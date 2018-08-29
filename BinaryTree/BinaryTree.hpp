#pragma once

#include <iostream>

template <class T>
struct BinaryTreeNode {
    T data_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;
    BinaryTreeNode(const T& data)
      : data_(data)
      , left_(nullptr)
      , right_(nullptr) {
          std::cout << "construct binarytree node: " << data << std::endl;
      }
};

template <class T>
class BinaryTree {
    using Node = BinaryTreeNode<T>;
protected:
    Node* CreateTree(T* a, size_t n, const T& invalid, size_t index) {
        Node* root = nullptr;
        if (index < n && a[index] != invalid) {
            root = new Node(a[index]);
            root->left_ = CreateTree(a, n, invalid, ++index);
            root->right_ = CreateTree(a, n, invalid, ++index);
        }
        return root;
    }
public:
    BinaryTree()
        : root_(nullptr) {}
    BinaryTree(T*a, size_t n, const T& invalid) {
        size_t index = 0;
        root_ = CreateTree(a, n, invalid, 0);
    }
    BinaryTree(const BinaryTree<T>& t) {
    }
    BinaryTree<T> operator=(const BinaryTree<T>& t) {
        return *this;
    }

private:
    Node* root_;
};