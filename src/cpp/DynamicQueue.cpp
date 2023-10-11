#include <cstddef>
#include <iostream>

struct Node {
  int key;
  Node *next;

  Node(int key) : key(key), next(nullptr) {}
};

class DynamicQueue {
 private:
  Node *_begin;
  Node *_end;

 public:
  DynamicQueue() : _begin(nullptr), _end(nullptr) {}

  ~DynamicQueue() {
    while (_begin) {
      Node *tmp = _begin;
      _begin = _begin->next;
      delete tmp;
    }
  }

  bool isEmpty(void) const { return _begin == nullptr; }

  void enqueue(int key) {
    Node *node = new Node(key);

    if (isEmpty()) {
      _begin = node;
    } else {
      _end->next = node;
    }
    _end = node;
  }

  Node *dequeue(void) {
    if (isEmpty()) {
      return nullptr;
    }

    Node *removed = _begin;
    _begin = _begin->next;
    if (isEmpty()) {
      _end = nullptr;
    }
    return removed;
  }

  size_t size(void) const {
    size_t size = 0;

    Node *curr = _begin;
    while (curr) {
      ++size;
      curr = curr->next;
    }

    return size;
  }

  void print(void) const {
    if (isEmpty()) {
      std::cout << "empty queue";
    } else {
      Node *curr = _begin;
      while (curr) {
        std::cout << curr->key << ' ';
        curr = curr->next;
      }
    }
    std::cout << std::endl;
  }
};

int main(void) {
  DynamicQueue queue;

  queue.enqueue(42);
  queue.enqueue(5);
  queue.enqueue(1231);
  queue.enqueue(515);
  queue.print();  // 42 5 1231 515

  // Use 'delete' keyword to make the code leak-free
  queue.dequeue();
  queue.dequeue();
  queue.print();  // 1231 515
  return 0;
}
