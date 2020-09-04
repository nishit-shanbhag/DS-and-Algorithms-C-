//
// Created by Nishit on 10-02-2020.
//
#include <iostream>
#include <vector>

using namespace std;

class Node {
    Node *next;
    int coef;
    int expo;
public:
    Node(int c, int e) {
        next = nullptr;
        coef = c;
        expo = e;
    }

    void setNext(Node *nxt) {
        next = nxt;
    }

    int getExponent() {
        return expo;
    }

    int getCoefficient() {
        return coef;
    }

    Node *getNext() {
        return next;
    }
};

Node *head1 = nullptr;
Node *head2 = nullptr;
Node *head3 = nullptr;

void Enqueue(int coef, int expo, int op) {
    Node *pt;
    if (op == 0)
        pt = head1;
    else if (op == 1)
        pt = head2;
    else
        pt = head3;
    Node *ins = new Node(coef, expo);
    if (pt != nullptr) {
        while (pt->getNext() != nullptr) { pt = pt->getNext(); }
        pt->setNext(ins);
    } else {
        if (op == 0)
            head1 = new Node(coef, expo);
        else if (op == 1)
            head2 = new Node(coef, expo);
        else
            head3 = new Node(coef, expo);

    }
}

void Dequeue(Node *head) {
    Node *pt = head;
    if (pt == nullptr) { cout << "Linked List underflow!" << endl; }
    else {
        pt = head->getNext();
        delete head;
        head = pt;
    }
}

void printLinkedList(Node *head) {
    Node *pt = head;
    while (pt != nullptr) {
        cout << pt->getCoefficient() << "x^" << pt->getExponent();
        pt = pt->getNext();
        if (pt != nullptr)
            cout << " + ";
        else
            cout << endl;
    }
}

int convert2num(string str) {
    int num = 0;
    for (int i = 0; i < str.length(); ++i) {
        num = num * 10 + (str[i] - 48);
    }
    return num;
}

vector<vector<int>> convertStringinput2Vector(string eq1) {
    //converting string input to array
    vector<vector<int>> data1;
    string temp = "";
    for (int i = 0; i < eq1.length(); i++) {
        if (eq1[i] != '+' && eq1[i] != '-' && eq1[i] != '*' && eq1[i] != '/' && eq1[i] != ')') {
            temp += eq1[i];
        } else {
            int coef = -1, expo = -1;
            string num;
            for (int j = 0; j < temp.length(); ++j) {
                if (temp[j] != 'x' && temp[j] != 'X') {
                    num += temp[j];
                } else {
                    coef = convert2num(num);
                    num = "";
                }
            }
            expo = convert2num(num);
            vector<int> dtemp;
            dtemp.push_back(coef);
            dtemp.push_back(expo);
            data1.push_back(dtemp);
            temp = "";
        }
    }
    return data1;
}

int main() {
    vector<vector<int>> data1, data2;
    string eq1, eq2;
    cout<<"Input format example: 10x10+8x3) 10x10+2x3+1x2+1x1+1x0)"<<endl;
    cout << "Enter the first polynomial equation: "<<endl;
    cin >> eq1;
    cout << "Enter the second polynomial equation: "<<endl;
    cin >> eq2;

    data1 = convertStringinput2Vector(eq1);
    data2 = convertStringinput2Vector(eq2);

    //converting data to linkedList
    for (int i = 0; i < data1.size(); ++i) {
        Enqueue(data1[i][0], data1[i][1], 0);
    }
    for (int i = 0; i < data2.size(); ++i) {
        Enqueue(data2[i][0], data2[i][1], 1);
    }
    cout<<"Equation 1: ";
    printLinkedList(head1);
    cout<<"Equation 2: ";
    printLinkedList(head2);

    //addition of 2 equations
    Node *p1 = head1;
    Node *p2 = head2;
    while (p1 != nullptr and p2 != nullptr) {
        if (p1->getExponent() > p2->getExponent()) {
            Enqueue(p1->getCoefficient(), p1->getExponent(), 3);
            p1 = p1->getNext();
        } else if (p1->getExponent() < p2->getExponent()) {
            Enqueue(p2->getCoefficient(), p2->getExponent(), 3);
            p2 = p2->getNext();
        } else {
            Enqueue(p2->getCoefficient() + p1->getCoefficient(), p2->getExponent(), 3);
            p2 = p2->getNext();
            p1 = p1->getNext();
        }
    }
    Node *last = head3;
    if (last != nullptr) {
        while (last->getNext() != nullptr) {
            last = last->getNext();
        }
    }

    if (p1 != nullptr) {
        last->setNext(p1);
    }
    else if(p2!=nullptr){
        last->setNext(p2);
    }
    cout<<"Result: ";
    printLinkedList(head3);
    return 0;
}
