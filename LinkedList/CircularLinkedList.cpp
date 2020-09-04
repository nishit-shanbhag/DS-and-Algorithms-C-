//
// Created by nishi on 28-03-2020.
//

#include <iostream>

using namespace std;

class LinkedList {
public:
    LinkedList *next;
    int data;

    LinkedList(int n) {
        data = n;
        next = nullptr;
    }

    LinkedList(int n, LinkedList *nxt) {
        data = n;
        next = nxt;
    }
};


LinkedList *head = nullptr, *p = nullptr, *q = nullptr;

void printList() {
    if (head == nullptr) {
        cout << "List is empty";
    } else {
        LinkedList *l = head;
        do {
            cout << l->data << " --> ";
            l = l->next;
        } while (l != head);
    }
    cout << endl;
}

void circularPrint() {
    if (head == nullptr) {
        cout << "List is empty";
    } else {
        LinkedList *l = head;
        while (true) {
            cout << l->data << " --> ";
            l = l->next;
        }
    }
    cout << endl;
}


void deleteAtStart() {
    if (head == nullptr)
        cout << "List not found" << endl;
    else if (head->next == head)
        head = nullptr;
    else {
        p = head;
        q = head;
        head = head->next;
        while (q->next != p) {
            q = q->next;
        }
        q->next = head;
        delete p;
    }
}


void deleteNode(int data) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    if (head->data == data) {
        deleteAtStart();
        return;
    }
    bool found = false;
    p = head;
    LinkedList *prev;

    do {
        if (p->data == data) {
            found = true;
            break;
        }
        prev = p;
        p = p->next;
    } while (p != head);
    if (found) {
        prev->next = p->next;
        delete p;
    } else cout << "Not found" << endl;
}

void deleteAtEnd() {
    if (head == nullptr)
        cout << "List not found" << endl;
    else if (head->next == head)
        head = nullptr;
    else {
        p = head;
        LinkedList *pr = head;
        while (p->next != head) {
            pr = p;
            p = p->next;
        }
        delete p;
        pr->next = head;
    }
}

void insertAtEnd(int data) {
    if (head == nullptr) {
        head = new LinkedList(data);
        head->next = head;
        cout << "Inserted at head" << endl;
    } else {
        p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = new LinkedList(data, head);
    }
}

void insertBefore(int before, int data) {
    bool flag = false;
    if (head == nullptr) {
        head = new LinkedList(data);
        head->next = head;
        cout << "Inserted" << endl;
    } else if (head->data == before) {
        p = head;
        head = new LinkedList(data, p);
        q = p;
        while (q->next != p) {
            q = q->next;
        }
        q->next = head;

    } else {
        LinkedList *l = head;
        LinkedList *prev;
        do {
            if (l->data == before) {
                flag = true;
                break;
            }
            prev = l;
            l = l->next;
        } while (l != head);
        if (flag) {
            prev->next = new LinkedList(data);
            prev->next->next = l;
        } else cout << "Not found" << endl;
    }
}

void insertAtStart(int data) {
    if (head == nullptr) {
        cout << "Linked list not found";
    } else {
        p = head;
        while (p->next != head) {
            p = p->next;

        }
        p->next = new LinkedList(data, head);
        head = p->next;
    }
}

void insertAfter(int after, int data) {
    LinkedList *l = head;
    bool flag = false;
    do {
        if (l->data == after) {
            flag = true;
            break;
        }
        l = l->next;
    }while (l != head);
    p = l->next;
    if (flag) {
        l->next = new LinkedList(data);
        l->next->next = p;
    } else
        cout << "Not found" << endl;
}

void reverse() {
    if (head == nullptr)
        cout << "List is empty" << endl;
    else {
        LinkedList *f, *s, *t;
        f = s = t = head;
        do {
            f = s;
            s = t;
            t = t->next;
            s->next = f;
        }while (t != head);
        head->next = s;
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

    while (true) {
        j = i;
        while (true) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
            if(j==head)
                break;
        }
        i = i->next;
        if(i==head)
            break;
    }
}



int count() {
    p = head;
    int count = 0;
    do {
        p = p->next;
        count++;
    }while (p != head);
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
    cout<<"12. Circular print\n";
    cout<<"13. Exit\n";
    do {
        cout<<"Enter option: "<<endl;
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
                circularPrint();
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
