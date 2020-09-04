//
// Created by nishit on 12-03-2020.
//
#include <iostream>
#include <vector>

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

    void setData(int d) {
        data = d;
    }

    Node *getNext() {
        return next;
    }
};

Node *head = nullptr;

//counting elements 12
int countElements() {
    Node *p = head;
    int counter = 0;
    while (p != nullptr) {
        counter++;
        p = p->getNext();
    }
    return counter;
}

//insert at start 1
void insertAtStart(int data) {
    Node *ins = new Node(data);
    if (head == nullptr) {
        head = ins;
    } else {
        ins->setNext(head);
        head = ins;
    }
}

//insert at end 2
void insertAtEnd(int data) {
    Node *ins = new Node(data);
    if (head == nullptr) {
        head = ins;
    } else {
        Node *p = head;
        while (p->getNext() != nullptr) {
            p = p->getNext();
        }
        p->setNext(ins);
    }
}

//insert before element 3
void insertBeforeElement(int data, int element) {
    if (head == nullptr) {
        cout << "Element not found!" << endl;
    } else {
        Node *ins = new Node(data);
        Node *p = head;
        Node *prev = p;
        while (p != nullptr and p->getData() != element) {
            prev = p;
            p = p->getNext();
        }
        if (p == nullptr) {
            cout << "Element not found!" << endl;
        } else if (prev == p) {
            ins->setNext(head);
            head = ins;
        } else {
            cout << "Element found, inserting " << data << endl;
            prev->setNext(ins);
            ins->setNext(p);
        }
    }
}

//insert after element 4
void insertAfterElement(int data, int element) {
    if (head == nullptr) {
        cout << "Element not found!" << endl;
    } else {
        Node *ins = new Node(data);
        Node *p = head;
        while (p != nullptr and p->getData() != element) {
            p = p->getNext();
        }
        if (p == nullptr) {
            cout << "Element not found!" << endl;
        } else {
            cout << "Element found, inserting " << data << endl;
            ins->setNext(p->getNext());
            p->setNext(ins);
        }
    }
}

//delete from start 5
void deleteFromStart() {
    if (head == nullptr) {
        cout << "Linked List is empty!" << endl;
    } else {
        Node *p = head;
        head = head->getNext();
        delete p;
    }
}

//delete from end 6
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "Linked List is empty!" << endl;
    } else {
        Node *p = head;
        Node *prev = p;
        while (p->getNext() != nullptr) {
            prev = p;
            p = p->getNext();
        }
        if (prev == p) {
            head = nullptr;
        } else {
            prev->setNext(nullptr);
        }
        delete p;
    }
}

//delete particular element 7
void deleteAnElement(int ele) {
    if (head == nullptr) {
        cout << "Linked List is empty!" << endl;
    } else {
        Node *p = head;
        Node *prev = p;
        while (p->getNext() != nullptr and p->getData() != ele) {
            prev = p;
            p = p->getNext();
        }
        if (prev == p) {
            head = head->getNext();
        } else {
            prev->setNext(p->getNext());
        }
        delete p;
    }
}

//print linked list 8
void printLinkedList() {
    Node *p = head;
    if (head == nullptr) {
        cout << "Linked list is Empty!" << endl;
    } else {
        while (p != nullptr) {
            cout << p->getData() << "->";
            p = p->getNext();
        }
        cout << "NULL" << endl;
    }
}

//sort linked list 9
void sortLinkedList() {
    int length = countElements();
    Node *p1 = head;
    Node *p2 = p1->getNext();
    if (p1 == nullptr or p2 == nullptr) {
        cout << "Either 0-1 elements in Linked List!";
    } else {
        for (int i = 1; i < length; ++i) {
            p1 = head;
            p2 = p1->getNext();
            for (int j = 0; j < length - i; ++j) {
                if (p1->getData() > p2->getData()) {
                    int temp = p1->getData();
                    p1->setData(p2->getData());
                    p2->setData(temp);
                }
                p1 = p2;
                p2 = p2->getNext();
            }
        }
    }

}

//reverse linked list 10
void reverseLinkedList() {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
    } else {
        Node *first = head;
        Node *second = first;
        Node *third = second->getNext();
        while(third!= nullptr){
            first = second;
            second = third;
            third= third->getNext();
            second->setNext(first);
        }head->setNext(nullptr);
        head=second;
    }
}

//search 11
void search(int d){
    if(head== nullptr){
        cout<<"Linked list is empty!"<<endl;
    }else{
        Node *p = head;
        int position = 1;
        while(p!=nullptr and p->getData()!=d){
            p=p->getNext();
            position++;
        }
        if(p== nullptr){
            cout<<"Data not found!"<<endl;
        }else{
            cout<<"Data found! at position "<<position<<endl;
        }
    }
}



int main() {
    int op;
    int data, ele;
    cout<<"1) Insert at start"<<endl;
    cout<<"2) Insert at end"<<endl;
    cout<<"3) Insert before element"<<endl;
    cout<<"4) Insert after element"<<endl;
    cout<<"5) Delete from start"<<endl;
    cout<<"6) Delete from end"<<endl;
    cout<<"7) Delete an element"<<endl;
    cout<<"8) Print linked list"<<endl;
    cout<<"9) Sort Linked list"<<endl;
    cout<<"10) Reverse Linked List"<<endl;
    cout<<"11) Search element"<<endl;
    cout<<"12) Count elements"<<endl;
    cout<<"13) Exit"<<endl;
    while (true) {
        cout << "Enter an option: " << endl;
        cin >> op;
        if (op == 1) {
            cout << "Enter the data to insert: " << endl;
            cin >> data;
            insertAtStart(data);
        } else if (op == 2) {
            cout << "Enter the data to insert: " << endl;
            cin >> data;
            insertAtEnd(data);
        } else if (op == 3) {
            cout << "Element the element to search: " << endl;
            cin >> ele;
            cout << "Enter the data to insert: " << endl;
            cin >> data;
            insertBeforeElement(data, ele);
        } else if (op == 4) {
            cout << "Element the element to search: " << endl;
            cin >> ele;
            cout << "Enter the data to insert: " << endl;
            cin >> data;
            insertAfterElement(data, ele);
        } else if (op == 5) {
            deleteFromStart();
        } else if (op == 6) {
            deleteFromEnd();
        } else if (op == 7) {
            cout << "Element the element to search: " << endl;
            cin >> ele;
            deleteAnElement(ele);
        } else if (op == 8) {
            printLinkedList();
        } else if (op == 9) {
            sortLinkedList();
        } else if (op == 10) {
            reverseLinkedList();
        } else if (op == 11) {
            cout << "Element the element to search: " << endl;
            cin >> ele;
            search(ele);
        } else if (op == 12) {
            cout << "Linked list length: " << countElements() << endl;
        }
        else if (op == 13) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid Option!" << endl;
        }
    }
    return 0;
}

