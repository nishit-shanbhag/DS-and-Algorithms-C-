//
// Created by Nishit on 16-02-2020.
//
#include <iostream>

using namespace std;

class Node {
    Node *next;
    int data;
public:
    Node(int d) {
        next = nullptr;
        data = d;
    }

    void setNext(Node *nxt) {
        next = nxt;
    }

    int getData() {
        return data;
    }

    int setData(int d) {
        data = d;
    }

    Node *getNext() {
        return next;
    }
};

Node *top = nullptr;
Node *head = nullptr;

void Push(int d) {
    Node *pt = head;
    Node *ins = new Node(d);
    if (top == nullptr) {
        head = ins;
        top = ins;
    } else {
        top->setNext(ins);
        top = ins;
    }
}

void Pop() {
    Node *prev = head;
    if(top==prev){
        delete top;
        top = nullptr;
        head = nullptr;
    }
    else if (top != nullptr) {
        while (prev->getNext() != top) {
            prev = prev->getNext();
        }
        prev->setNext(nullptr);
        delete top;
        top = prev;
    } else {
        cout << "Stack underflow!" << endl;
    }
}

void displayTop() {
    cout << "Top: " << top->getData() << endl;
}

void printLinkedList() {
    if(top!= nullptr) {
        Node *pt = head;
        while (pt != nullptr) {
            cout << pt->getData() << " ";
            pt = pt->getNext();
        }
        cout << endl;
    }else{
        cout<<"Stack is empty!"<<endl;
    }
}

int main() {
    int op;
    do {
        cout << "1) Push" << endl;
        cout << "2) Pop" << endl;
        cout << "3) Display" << endl;
        cout << "4) Display Top" << endl;
        cout << "5) Exit" << endl;
        cout << "Enter a choice: " << endl;
        cin >> op;
        int temp;
        if (op == 1) {
            cout << "Enter value to enter: " << endl;
            cin >> temp;
            Push(temp);
        } else if (op == 2) {
            Pop();
        } else if (op == 3) {
            printLinkedList();
        } else if (op == 4) {
            displayTop();
        } else {
            break;
        }
    } while (1);

    return 0;
}
