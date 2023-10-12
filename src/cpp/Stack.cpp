#include <iostream>

// MAX is a macro to define all stack instances size
#define MAX 10
#define TYPE_SIZE 4

// Stack: Last In - First Out (LIFO)

class Stack {
    private:
    int arr[MAX];
    int elements{0};
    
    public:
    Stack(){}

    bool insert(int element) {
        if ((this->elements * TYPE_SIZE) == sizeof(this->arr)) {
            return false;
        };
        this->arr[elements] = element;
        elements++;
        return true;
    }

    bool isEmpty() {
        if (!this->elements) {
            return true;
        }
        return false;
    }

    bool remove() {
        if (this->isEmpty()) {
            return false;
        }
        this->arr[this->elements - 1] = 0;
        elements--;
        return true;
    }

    int top() {
        if (this->isEmpty()) {
            return -1;
        }
        return this->arr[this->elements - 1];
    }

    int getSize() {
        return sizeof(this->arr) / TYPE_SIZE;
    }
};

int main() {
    // Create a pointier to a new Stack instance
    Stack* stack = new Stack();

    // Insert Elements, then removes
    stack->insert(1);
    stack->insert(2);
    stack->insert(4);
    std:: cout << stack->top() << std::endl;
    stack->remove();
    std:: cout << stack->top() << std::endl;
    stack->remove();
    stack->remove();

    std::cout << "--------------------" << "\n";
    
    // Try to insert beyond max size
    for (int i = 0; i < 15; i++) {
        std::cout << stack->insert(i) << std::endl;
    }

    std::cout << "--------------------" << "\n";

    // Show and remove stack top element
    for (int i = 0; i < stack->getSize(); i++) {
        std::cout << stack->top() << std::endl;
        stack->remove();
    }   
}
