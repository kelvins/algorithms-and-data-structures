#include <iostream>

class Stack {
  struct node {
    int data;
    node *next;
  };
  node *head = nullptr;

public:
  static constexpr int emptyStack = -1;

  void push(int value) {
    node *newNode;
    newNode = new node;
    newNode->data = value;

    if (head == nullptr) {
      newNode->next = nullptr;
    } else {
      newNode->next = head;
    }
    head = newNode;
  }

  bool isEmpty() { return head == nullptr; }

  int pop() {
    int value = emptyStack;
    if (!isEmpty()) {
      value = head->data;
      node *next, *at;
      next = head->next;
      at = head;
      head = next;
      delete at;
    }
    return value;
  }

  int showTop() {
    int value = emptyStack;
    if (!isEmpty()) {
      value = head->data;
    }
    return value;
  }

  int size() {
    int counter = 0;
    node *temp;
    temp = head;
    while (temp->next != nullptr) {
      counter++;
      temp = temp->next;
    }
    counter++;
    return counter;
  }
};

int main() {
  Stack stack;
  int value;

  for (int i = 0; i < 10; i++) {
    std::cout << "Push: " << i + 1 << std::endl;
    stack.push(i + 1);
  }

  for (int i = 0; i < 12; i++) {
    value = stack.pop();
    if (value != Stack::emptyStack) {
      std::cout << "Pop: " << value << std::endl;
    } else {
      std::cout << "Stack is empty!" << std::endl;
    }
  }

  for (int i = 0; i < 5; i++) {
    std::cout << "Push: " << i + 1 << std::endl;
    stack.push(i + 1);
  }

  std::cout << "Stack have " << stack.size() << " elements" << std::endl;
  std::cout << stack.showTop() << " is the top element of stack" << std::endl;
  return 0;
}
