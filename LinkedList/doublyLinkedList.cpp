//
// Created by nishit on 21-02-2020.
//
//
// Created by NIKHIL on 20-02-2020.
//

#include <iostream>

using namespace std;

class LinkedList {
public:
    LinkedList *next, *prev;
    int data;

    LinkedList(int n) {
        data = n;
        next = nullptr;
        prev = nullptr;
    }

    LinkedList(int n, LinkedList *previous) {
        data = n;
        next = nullptr;
        prev = previous;

    }

};

LinkedList *head = nullptr, *tail = nullptr, *p = nullptr, *pr = nullptr;


void printList() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
    } else {
        p = head;
        while (p != nullptr) {
            cout << p->data << " --> ";
            p = p->next;
        }
    }
    cout << endl;
}

void printListFromEnd() {
    if (tail == nullptr)
        cout << "List is empty" << endl;
    else {
        p = tail;
        while (p != nullptr) {
            cout << p->data << " --> ";
            p = p->prev;
        }
    }
    cout << endl;
}

void deleteNode(int data) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    if (head->data == data) {

        p = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;

            head->prev = nullptr;
        }
        delete p;
        return;
    }
    if (tail->data == data) {
        p = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete p;
        return;
    }
    bool found = false;
    p = head;
    LinkedList *prev;
    while (p != nullptr) {
        if (p->data == data) {
            found = true;
            break;
        }
        prev = p;
        p = p->next;
    }
    if (found) {
        prev->next = p->next;
        p->next->prev = prev;
        delete p;
    } else cout << "Not found" << endl;
}

void deleteAtStart() {
    if (head == nullptr)
        cout << "List not found" << endl;
    else {
        p = head;
        head = head->next;
        delete p;
    }
}

void deleteAtEnd() {
    if (head == nullptr)
        cout << "List not found" << endl;
    else if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        p = head;
        pr = head;
        while (p->next != nullptr) {
            pr = p;
            p = p->next;
        }
        delete p;
        tail = pr;
        pr->next = nullptr;
    }

}

void insertAtEnd(int data) {
    if (head == nullptr) {
        head = new LinkedList(data, nullptr);
        tail = head;
        cout << "Inserted at head" << endl;
    } else {
        p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = new LinkedList(data, p);
        tail = p->next;
    }
}

void insertBefore(int before, int data) {

    bool flag = false;
    if (head == nullptr) {
        head = new LinkedList(data);
        cout << "Inserted" << endl;
    } else if (head->data == before) {
        p = head;
        head = new LinkedList(data);
        p->prev = head;
        head->next = p;
    } else {
        LinkedList *l = head;
        LinkedList *prev;
        while (l != nullptr) {
            if (l->data == before) {
                flag = true;
                break;
            }
            prev = l;
            l = l->next;
        }
        if (flag) {
            prev->next = new LinkedList(data, prev);
            prev->next->next = l;
            l->prev = prev->next;
        } else cout << "Not found" << endl;
    }
}


void insertAtStart(int data) {
    if (head == nullptr) {
        head = new LinkedList(data);
        cout << "Inserted" << endl;
    } else {
        p = head;
        head = new LinkedList(data);
        head->next = p;
        p->prev = head;
    }
}


void insertAfter(int after, int data) {


    if (head == nullptr) {
        cout << "Linked list not found";
        return;
    }
    LinkedList *l = head;
    bool flag = false;
    while (l != nullptr) {
        if (l->data == after) {
            flag = true;
            break;
        }
        l = l->next;
    }
    p = l->next;
    if (flag) {

        l->next = new LinkedList(data, l);
        l->next->next = p;
        if (p == nullptr) {
            tail = l->next;
        } else
            p->prev = l->next;

    } else
        cout << "Not found" << endl;

}

void reverse() {
    if (head == nullptr)
        cout << "List is empty" << endl;
    else {
        LinkedList *f, *s, *t;
        f = s = t = head;

        while (t != nullptr) {
            f = s;
            s = t;
            t = t->next;
            s->next = f;
            s->prev = t;
        }
        tail = head;
        head->next = nullptr;
        head = s;
    }
}

void search(int dataToSearch) {
    p = head;
    while (p != nullptr) {
        if (p->data == dataToSearch) {
            cout << "Node found" << endl;
            return;
        }
        p = p->next;
    }
    cout << "Not found" << endl;
}


void sort() {
    p = head;
    LinkedList *i = p, *j = p;
    int temp;

    while (i != nullptr) {
        j = i;
        while (j != nullptr) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}


int count() {
    p = head;
    int count = 0;
    while (p != nullptr) {
        p = p->next;
        count++;
    }
    return count;
}

void menu() {
    int choice, temp, temp2;

    cout<<"1. Insert at end\n";
    cout<<"2. Insert at start\n";
    cout<<"3. Insert after a node\n";
    cout<<"4. Insert before a node\n";
    cout<<"5. Delete at start\n";
    cout<<"6. Delete at end\n";
    cout<<"7. Delete particular element\n";
    cout<<"8. Display\n";
    cout<<"9. Count nodes\n";
    cout<<"10. Sort the list\n";
    cout<<"11. Reverse List\n";
    cout<<"12. Display from end\n";
    cout<<"13. Exit\n";
    do {
        cout<< "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter data: " << endl;
                cin >> temp;
                insertAtEnd(temp);
                break;

            case 2:
                cout << "Enter data: " << endl;
                cin >> temp;
                insertAtStart(temp);
                break;
            case 3:

                cout << "Enter data: " << endl;
                cin >> temp;
                cout << "Enter the data after which you want to insert: " << endl;
                cin >> temp2;
                insertAfter(temp2, temp);
                break;
            case 4:
                cout << "Enter data: " << endl;
                cin >> temp;
                cout << "Enter the data before which you want to insert: " << endl;
                cin >> temp2;
                insertBefore(temp2, temp);
                break;
            case 5:
                deleteAtStart();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                cout << "Enter data to delete: " << endl;
                cin >> temp;
                deleteNode(temp);
                break;
            case 8:
                printList();
                break;
            case 9:
                cout << count() << endl;
                break;
            case 10:
                sort();
                break;
            case 11:
                reverse();
                break;
            case 12:
                printListFromEnd();
                break;
            case 13:
                cout << "Exiting.." << endl;
                break;
            default:
                cout << "Invalid Operation" << endl;
        }

    } while (choice != 13);

}

int main() {
    menu();

    return 0;

}

