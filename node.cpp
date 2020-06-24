#include "node.h"


Node::Node() {
    this->next = 0;
    val = 0;
}


Node::Node(int data) {
    this->val = data;
    this->next = nullptr;
}


Node::Node(int data, Node* addr) {
    this->val = data;
    this->next = addr;
}

