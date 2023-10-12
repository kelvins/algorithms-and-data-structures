#include <iostream>

// MAX is a macro to define all stack instances size
#define MAX 10

// Stack: Last In - First Out (LIFO)

class Stack {
    private:
    int array[MAX];
    int index = 0;
    
    public:
    Stack(){}

    void push(int element) {
        if (this->index >= MAX) {
            throw std::logic_error("Stack is full!");
        }
        this->array[index] = element;
        index++;
    }

    bool isEmpty() {
        if (!this->index) {
            return true;
        }
        return false;
    }

    int pop() {
        if (this->isEmpty()) {
            throw std::logic_error("Stack is empty!");
        }
        index--;
        int value = this->array[this->index];
        this->array[this->index] = 0;
        return value;
    }

    void print() {
        std::cout << "[ ";
        for (int i = 0; i < this->index; i++) {
            std::cout << this->array[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    // Create a pointier to a new Stack instance
    Stack* stack = new Stack();

    std::cout << "Push(1, 2, 4)" << std::endl;
    stack->push(1);
    stack->push(2);
    stack->push(4);
    stack->print();

    std::cout << "Pop()" << std::endl;
    stack->pop();
    stack->print();

    stack->pop();
    stack->pop();

    std::cout << "Empty Stack" << std::endl;
    stack->print();
}
