#include <iostream>

#include "SinglyLinkedList.h"


void SinglyLinkedList::addNode(Song data) {
    if (this->head == nullptr)
        this->head = new Node(data);
    else {
        Node* nextNode = this->head;
        this->head = new Node(data);
        this->head->next = nextNode;
    }
}

void SinglyLinkedList::removeNode(Song data) {
    Node* pre_node = nullptr;
    Node* curr_node = this->head;

    while (curr_node->next != nullptr){
        if (curr_node->data.equals(data)){
            pre_node->next = curr_node->next;
            break;
        }
        pre_node = curr_node;
        curr_node = curr_node->next;
    }
}

void SinglyLinkedList::printList() {
    std::cout << "Playlist:" << std::endl;
    Node* curr_node = this->head;
    while (curr_node->next != nullptr) {
        std::cout << curr_node->data.toString() << std::endl;
        curr_node = curr_node->next;
    }
    std::cout << curr_node->data.toString() << std::endl;
}

