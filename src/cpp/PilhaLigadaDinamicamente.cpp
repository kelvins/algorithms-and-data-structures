#include <iostream>

class Stack {
  struct node {
    int dado;
    node *prox;
  };
  node *head = nullptr;

public:
  static constexpr int stack_empty = -1;

  void push(int val) {
    node *elemento;
    elemento = new node;
    elemento->dado = val;
    if (head == nullptr) {
      // pilha vazia
      elemento->prox = nullptr;
      head = elemento;
    } else {
      // pilha com elemento
      elemento->prox = head;
      head = elemento;
    }
  }

  bool isempty() {
    if (head == nullptr) {
      return true;
    }
    return false;
  }

  int pop() {
    int val = stack_empty;
    if (!isempty()) {
      val = head->dado;
      node *next, *at;
      next = head->prox;
      at = head;
      head = next;
      delete at;
    }
    return val;
  }

  int show_top() {
    int val = stack_empty;
    if (!isempty()) {
      val = head->dado;
    }
    return val;
  }

  int size() {
    int cont = 0;
    node *aux;
    aux = head;
    while (aux->prox != nullptr) {
      cont++;
      aux = aux->prox;
    }
    cont++;
    return cont;
  }
};

int main() {
  Stack st;
  int val;

  for (int i = 0; i < 10; i++) {
    st.push((i + 1));
  }
  for (int i = 0; i < 12; i++) {
    val = st.pop();
    if (val != Stack::stack_empty) {
      std::cout << val << std::endl;
    } else {
      std::cout << "stack is empty!" << std::endl;
    }
  }

  for (int i = 0; i < 5; i++) {
    st.push((i + 1));
  }

  std::cout << "stack have " << st.size() << " elements" << std::endl;
  std::cout << st.show_top() << " is top element of stack" << std::endl;
  return 0;
}