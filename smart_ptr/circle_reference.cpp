#include <iostream>
#include <memory>

class Node {
    int value;
    public:
    std::shared_ptr<Node> leftPtr;
    std::shared_ptr<Node> rightPtr;
    std::weak_ptr<Node> parentPtr;
    Node(int val) : value(val) {
        std::cout << "Construct" << value << std::endl;
    }
    ~Node() {
        std::cout << "Destruct" << value << std::endl;
    }
};

int main(int argc, char* argv[]) {
    std::shared_ptr<Node> ptr = std::make_shared<Node>(4);
    ptr->leftPtr = std::make_shared<Node>(2);
    ptr->leftPtr->parentPtr = ptr;
    ptr->rightPtr = std::make_shared<Node>(5);
    ptr->rightPtr->parentPtr = ptr;
    std::cout << "ptr reference count = " << ptr.use_count() << std::endl;
    std::cout << "ptr leftPtr reference count = " << ptr->leftPtr.use_count() << std::endl;
    std::cout << "ptr rightPtr reference count = " << ptr->rightPtr.use_count() << std::endl;
    return 0;

}