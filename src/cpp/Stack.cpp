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

    bool push(int element) {
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

    bool pop() {
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
    stack->push(1);
    stack->push(2);
    stack->push(4);
    std:: cout << stack->top() << std::endl;
    stack->pop();
    std:: cout << stack->top() << std::endl;
    stack->pop();
    stack->pop();

    std::cout << "--------------------" << "\n";
    
    // Try to insert beyond max size
    for (int i = 0; i < 15; i++) {
        std::cout << stack->push(i) << std::endl;
    }

    std::cout << "--------------------" << "\n";

    // Show and remove stack top element
    for (int i = 0; i < stack->getSize(); i++) {
        std::cout << stack->top() << std::endl;
        stack->pop();
    }   
}
