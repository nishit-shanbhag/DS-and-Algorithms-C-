//
// Created by nishit on 19-03-2020.
//

#include <iostream>
#include <vector>

using namespace std;

class Node {
    Node *right;
    Node *left;
    int data;
public:
    explicit Node(int d) {
        right = nullptr;
        left = nullptr;
        data = d;
    }

    void set_right_more(Node *nxt) {
        right = nxt;
    }

    void set_left_less(Node *nxt) {
        left = nxt;
    }

    int getData() {
        return data;
    }

    void setData(int d) {
        data = d;
    }

    Node *get_left_less() {
        return left;
    }

    Node *get_right_more() {
        return right;
    }
};

class Stack_Node {
    Node *data;
    Stack_Node *next;
public:
    Stack_Node() {
        data = nullptr;
        next = nullptr;
    }

    Stack_Node(Node *d) {
        data = d;
        next = nullptr;
    }

    Node *getData() {
        return data;
    }

    void setNext(Stack_Node *n) {
        next = n;
    }

    Stack_Node *getNext() {
        return next;
    }
};

Node *root = nullptr;
Stack_Node *top = nullptr;

void insertAtBeg_Stack(Node *ins) {//push
    auto *ins_stack = new Stack_Node(ins);
    if (top != nullptr) {
        ins_stack->setNext(top);
        top = ins_stack;
    } else {
        top = ins_stack;
    }
}

Node *removeFromBeg_Stack() {//pop
    Node *ret = nullptr;
    if (top != nullptr) {
        Stack_Node *p = top->getNext();
        ret = top->getData();
        delete (top);
        top = p;
    }
    return ret;
}


void insert(int num) {
    Node *ins = new Node(num);
    if (root != nullptr) {
        Node *p = root;
        Node *prev = p;
        bool right = false;
        while (p != nullptr) {
            prev = p;
            if (p->getData() == num) {
                //found same value
                cout << "Inserted value already exists, therefore ignored" << endl;
                break;
            } else if (num > p->getData()) {
                p = p->get_right_more();
                right = true;
            } else if (num < p->getData()) {
                p = p->get_left_less();
                right = false;
            }
        }
        if (right) {
            prev->set_right_more(ins);
        } else {
            prev->set_left_less(ins);
        }
    } else {
        root = ins;
    }
}

void display(Node *self, int dash) {//using pre order-recursion
    if(self!= nullptr) {
        for (int i = 0; i < dash; ++i) {
            cout << " ";
        }
        cout << " |-" << self->getData() << endl;
        dash++;
        if (self->get_left_less() != nullptr)
            display(self->get_left_less(), dash);
        if (self->get_right_more())
            display(self->get_right_more(), dash);
    }else{
        cout<<"Tree is empty"<<endl;
    }
};

void display2(Node *self) {//using In order-recursion
    if (self->get_left_less() != nullptr)
        display2(self->get_left_less());
    cout << self->getData() << " ";
    if (self->get_right_more())
        display2(self->get_right_more());
}

void display3(Node *self) {//using post order-recursion
    if (self->get_left_less() != nullptr)
        display2(self->get_left_less());
    if (self->get_right_more())
        display2(self->get_right_more());
    cout << self->getData() << " ";
}

void display_without_recursion() {//using pre order
    insertAtBeg_Stack(root);
    while (top != nullptr) {
        Node *popped = removeFromBeg_Stack();
        if (popped != nullptr) {
            cout << popped->getData() << " ";
            if (popped->get_right_more() != nullptr)
                insertAtBeg_Stack(popped->get_right_more());
            if (popped->get_left_less() != nullptr)
                insertAtBeg_Stack(popped->get_left_less());
        } else {
            top = nullptr;
        }
    }
}

void display2_without_recursion() {//using in order
    Node *p = root;
    while (p != nullptr or top != nullptr) {
        while (p != nullptr) {
            insertAtBeg_Stack(p);
            p = p->get_left_less();
        }
        if (top != nullptr) {
            Node *popped = removeFromBeg_Stack();
            cout << popped->getData() << " ";
            p = popped->get_right_more();
        }
    }
}

void display3_without_recursion() {//TODO doesnt work
    Node *p = root;
    do {
        if (p != nullptr) {
            if (p->get_right_more() != nullptr)
                insertAtBeg_Stack(p->get_right_more());
            insertAtBeg_Stack(p);
            p = p->get_left_less();
        } else {
            Node *popped = removeFromBeg_Stack();
            if (popped->get_right_more() == nullptr) {
                cout << popped->getData() << " ";
                p = nullptr;
            } else if (popped->get_right_more() != nullptr and top->getData() == popped->get_right_more()) {
                Node *popped2 = removeFromBeg_Stack();
                insertAtBeg_Stack(popped);
                p = popped2;
            } else if (popped->get_right_more() != nullptr and top->getData() != popped->get_right_more()) {
                cout << popped->getData() << " ";
                p = nullptr;
            }
        }
    } while (top != nullptr);
}

void deleteItem(int num) {
    Node *p = root;
    Node *prev = p;
    bool right = false;
    while (p != nullptr) {
        if (num < p->getData()) {
            prev = p;
            right = false;
            p = p->get_left_less();
        } else if (num > p->getData()) {
            prev = p;
            right = true;
            p = p->get_right_more();
        } else {
            break;
        }
    }
    if (p != nullptr) {
        if (p->get_right_more() == nullptr and p->get_left_less() == nullptr) {//no child
            if(prev!=p) {
                if (right)
                    prev->set_right_more(nullptr);
                else
                    prev->set_left_less(nullptr);
            }else{
                root = nullptr;
            }delete (p);
        } else if (p->get_right_more() != nullptr and p->get_left_less() == nullptr) {//one right child
            if(p!=prev){
                if (right)
                    prev->set_right_more(p->get_right_more());
                else
                    prev->set_left_less(p->get_right_more());
                delete (p);
            }else{
                root = p->get_right_more();
            }
        } else if (p->get_right_more() == nullptr and p->get_left_less() != nullptr) {//one left child
            if(p!=prev){
                if (right)
                    prev->set_right_more(p->get_left_less());
                else
                    prev->set_left_less(p->get_left_less());
                delete (p);
            }else{
                root = p->get_left_less();
            }
        } else if (p->get_right_more() != nullptr and p->get_left_less() != nullptr) {//2 child
            Node *cur = nullptr;
            if (p->get_right_more()->get_left_less() != nullptr)
                cur = p->get_right_more();
            else
                cur = p->get_left_less();
            Node *cur_prev = cur;
            while (cur->get_left_less() != nullptr) {
                cur_prev = cur;
                cur = cur->get_left_less();
            }
            cur_prev->set_left_less(nullptr);
            if(p!=prev) {
                if (right)
                    prev->set_right_more(cur);
                else
                    prev->set_left_less(cur);
            }else{
                root = cur;
            }
            if(cur!=p->get_left_less())
                cur->set_left_less(p->get_left_less());
            else
                cur->set_left_less(nullptr);
            if(cur!=p->get_right_more()){
                Node *nright = cur;
                while(nright->get_right_more()!= nullptr){
                    nright=nright->get_right_more();
                }
                nright->set_right_more(p->get_right_more());
            }
            else
                cur->set_right_more(nullptr);
            delete (p);
        }
    } else {
        cout << "Element not found" << endl;
    }
}

int main() {
    int op, num;
    cout<<"1) Insert"<<endl;
    cout<<"2) Display(Default) pre order with recursion"<<endl;
    cout<<"3) Display in order with recursion"<<endl;
    cout<<"4) Display post order with recursion"<<endl;
    cout<<"5) Display pre order without recursion"<<endl;
    cout<<"6) Display in order without recursion"<<endl;
    cout<<"7) Display post order without recursion"<<endl;
    cout<<"8) Search and delete"<<endl;
    while (true) {

        cout << "Enter option: " << endl;
        cin >> op;
        if (op == 1) {//insert
            cout << "Enter the value to insert: " << endl;
            cin >> num;
            insert(num);
        } else if (op == 2) {//display pre order -r
            display(root, 0);
        } else if (op == 3) {// display in order -r
            display2(root);
            cout << endl;
        } else if (op == 4) {// display post order -r
            display3(root);
            cout << endl;
        } else if (op == 5) {// display pre order
            display_without_recursion();
            cout << endl;
        } else if (op == 6) {// display in order
            display2_without_recursion();
            cout << endl;
        } else if (op == 7) {// display post order
            display3_without_recursion();
            cout << endl;
        } else if (op == 8) {// delete & search included
            cout << "Enter the value to delete: " << endl;
            cin >> num;
            deleteItem(num);
        } else {
            break;
        }
    }
    return 0;
}

