#include <iostream>

class Node {
private:
  int value;

public:
  Node *next{nullptr};
  Node *previous{nullptr};

  // Node constructor
  Node(int value) { this->value = value; }

  int getValue() { return this->value; };
};

class DoublyLinkedList {
private:
  Node *first{nullptr};

  // Receives the node reference and make the pointers around stop pointing to
  void remove_pointers_to(Node *&node) {
    if (node->next) {
      node->next->previous = node->previous;
    }
    if (node->previous) {
      node->previous->next = node->next;
    } else {
      this->first = node->next;
    }
  }

public:
  DoublyLinkedList() {}

  void push_front(int value) {
    // Initialize a pointier to a new node with received value
    Node *node = new Node(value);
    // Node points to the first
    node->next = this->first;

    // If there is a first node, make him point to new node
    if (this->first) {
      this->first->previous = node;
    }

    // Node becomes the first
    this->first = node;
  }

  // Checks if there is a first node
  bool isEmpty() {
    if (!this->first) {
      return true;
    }
    return false;
  }

  void push_back(int value) {
    Node *node = new Node(value);
    Node *selectedNode = this->first;

    if (this->isEmpty()) {
      this->first = node;
      return;
    }

    Node *aux{nullptr};
    while (selectedNode) {
      aux = selectedNode;
      selectedNode = selectedNode->next;
    }

    node->previous = aux;
    aux->next = node;
  };

  void remove(int value) {
    // Throw exception to empty List
    if (this->isEmpty()) {
      throw std::logic_error("List is empty, nothing to be removed!");
    }

    // Initialize a pointier to first element
    Node *node = this->first;

    // Go through the list until find the value or the end
    while ((node) && (node->getValue() != value)) {
      node = node->next;
    }
    // Throw exception if didn't find the value
    if (!node) {
      throw std::logic_error("Value must be in the list!");
    }

    // Remove all pointier to the value if exists
    this->remove_pointers_to(node);

    // Delete node
    delete (node);
  }

  // Removes the k-th element, where k it's an ordinal number
  void remove_ordinary(int position) {
    if (this->isEmpty()) {
      throw std::logic_error("List is empty, nothing to be removed!");
    }

    if (position < 1) {
      throw std::logic_error("Invalid position!");
    }

    Node *selectedNode = this->first;
    int aux = 1;

    while ((selectedNode) && (aux != position)) {
      selectedNode = selectedNode->next;
      aux++;
    }

    if (!selectedNode) {
      throw std::logic_error("Index out of bound!");
    }

    this->remove_pointers_to(selectedNode);

    delete (selectedNode);
  }

  std::pair<bool, Node *> find(int value) {
    // Throw exception to empty List
    if (this->isEmpty()) {
      throw std::logic_error("List is empty, nothing to be removed!");
    }

    // Initialize a pointier to first element
    Node *node = this->first;

    // Go through the list until find the value or the end
    while ((node) && (node->getValue() != value)) {
      node = node->next;
    }

    if (!node) {
      return {false, nullptr};
    }
    return {true, node};
  }

  void print() {
    Node *selectedNode = this->first;
    std::cout << "[ ";
    while (selectedNode) {
      std::cout << selectedNode->getValue() << " ";
      selectedNode = selectedNode->next;
    }
    std::cout << "]" << std::endl;
  }
};

int main() {
  DoublyLinkedList *doubly_linked_list = new DoublyLinkedList();

  std::cout << "Push_front(20, 30, 40):" << std::endl;
  doubly_linked_list->push_front(20);
  doubly_linked_list->push_front(30);
  doubly_linked_list->push_front(40);

  doubly_linked_list->print();

  std::cout << "Remove second!" << std::endl;

  doubly_linked_list->remove_ordinary(2);

  doubly_linked_list->print();

  std::cout << "Remove(20, 40)!" << std::endl;
  doubly_linked_list->remove(20);
  doubly_linked_list->remove(40);

  std::cout << "List is empty: ";
  doubly_linked_list->print();

  std::cout << "Push_back(512, 123, 412)!" << std::endl;
  doubly_linked_list->push_back(512);
  doubly_linked_list->push_back(123);
  doubly_linked_list->push_back(412);

  doubly_linked_list->print();
}
