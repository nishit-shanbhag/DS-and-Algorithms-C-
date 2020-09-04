//
// Created by Nishit on 10-02-2020.
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

Node *head = nullptr;

void del(int num) {
    Node *pt = head;
    Node *pre = pt;
    bool found = false;
    while (pt->getData() != num) {
        found = true;
        pre = pt;
        pt = pt->getNext();
    }
    if (found) {
        pre->setNext(pt->getNext());
        delete pt;
    } else {
//        head=head->getNext();
        cout << "Not found!" << endl;
    }
}

void insert(int num, int d) {
    Node *pt = head;
    Node *pre = pt;
    Node *ins = new Node(d);
    bool found = false;
    while (pt->getData() != num) {
        found = true;
        pre = pt;
        pt = pt->getNext();
    }
    if (found) {
        pre->setNext(ins);
        ins->setNext(pt);
    } else {
        ins->setNext(head);
        head = ins;
    }
}

void Enqueue(int d) {
    Node *pt = head;
    Node *ins = new Node(d);
    if (pt != nullptr) {
        while (pt->getNext() != nullptr) {
            pt = pt->getNext();
        }
        pt->setNext(ins);
    } else {
        head = new Node(d);
    }
}

void Dequeue() {
    Node *pt = head;
    if (pt == nullptr) {
        cout << "Linked List underflow!" << endl;
    } else {
        pt = head->getNext();
        delete head;
        head = pt;
    }
}

void printLinkedList() {
    Node *pt = head;
    while (pt != nullptr) {
        cout << pt->getData() << " ";
        pt = pt->getNext();
    }
    cout << endl;
}

int main() {
    int op;
    do {
        cout << "1) Enqueue" << endl;
        cout << "2) Dequeue" << endl;
        cout << "3) Display" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter a choice: " << endl;
        cin >> op;
        int temp;
        if (op == 1) {
            cout << "Enter value to enter: " << endl;
            cin >> temp;
            Enqueue(temp);
        } else if (op == 2) {
            Dequeue();
        } else if (op == 3) {
            printLinkedList();
        } else if (op == 4) {
            break;
        }
    } while (1);

    return 0;
}
