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

    cout << '[';
    while(aux) {

        cout << aux->val;

        if(aux->next) {
            cout << ", ";
        }

        aux = aux->next;
    }
    cout << ']' << endl;
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

    Node *newNode = new Node(val, *head);

    *head = newNode;
}

void insert_in_position(Node **head, int val, int pos) {

    if(pos == 0) {
        push_front(head, val);
        return;
    }

    Node* newNode = new Node(val);

    auto prev = *head;
    auto curr = *head;

    while(curr->next && pos) {
        prev = curr;
        curr = curr->next;
        pos--;
    }

    prev->next = newNode;
    newNode->next = curr;    
}

void pop_back(Node **head) {

    if(*head == nullptr) {
        return;
    }

    auto prev = *head;
    auto curr = prev->next;

    while(curr->next) {
        prev = prev->next;
        curr = curr->next;
    }

    prev->next = nullptr;

    delete(curr);
}

void pop_front(Node **head) {

    if(*head == nullptr) {
        return;
    }

    auto aux = *head;

    *head = aux->next;

    delete(aux);
}

void remove_from_position(Node **head, int pos) {

    if(*head == nullptr) {
        return;
    }

    if(pos == 0) {
        pop_front(head);
        return;
    }

    auto prev = *head;
    auto curr = *head;

    while(curr->next && pos) {
        prev = curr;
        curr = curr->next;
        pos--;
    }

    if(pos == 0) {
        prev->next = curr->next;
        delete(curr);
    }
}

int main() {

    Node *head = nullptr;

    cout << "Inserindo no final os elementos [1, 2, 3]:" << endl;
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    print_list(head);

    cout << "Inserindo no inicio os elementos [0, -1, -2]:" << endl;
    push_front(&head, 0);
    push_front(&head, -1);
    push_front(&head, -2);
    print_list(head);

    cout << "Inserindo nas posicoes 3, 4, 5 os elementos [997, 998, 999] respectivamente:" << endl;
    insert_in_position(&head, 997, 3);
    insert_in_position(&head, 998, 4);
    insert_in_position(&head, 999, 5);
    print_list(head);

    cout << "Removendo ultimo elemento:" << endl;
    pop_back(&head);
    print_list(head);
    
    cout << "Removendo primeiro elemento:" << endl;
    pop_front(&head);
    print_list(head);

    cout << "Removendo elemento na posicao 2:" << endl;
    remove_from_position(&head, 2);
    print_list(head);
}
