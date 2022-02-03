#include <iostream>

using namespace std;

struct Node{

    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node *next) : val(val), next(next) {}    
};

void print_list(Node *head) {

    auto aux = head;
    while(aux) {

        cout << aux->val;

        if(aux->next) {
            cout << " -> ";
        }

        aux = aux->next;
    }
    cout << endl;
}

void push_back(Node **head, int val) {


    Node *newNode = new Node(val);

    if(*head == nullptr) {
        *head = newNode;
    }

    else {

        auto aux = *head;

        while(aux->next) {
            aux = aux->next;
        }

        aux->next = newNode;
    }
}

void push_front(Node **head, int val) {


    Node *newNode = new Node(val);

    if(*head == nullptr) {
        *head = newNode;
    }

    else {

        auto aux = *head;

        while(aux->next) {
            aux = aux->next;
        }

        aux->next = newNode;
    }
}

int main() {

    Node *head = nullptr;


    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);
    print_list(head);
}