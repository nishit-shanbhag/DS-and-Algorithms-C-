//
// Created by nishi on 27-03-2020.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> input;

class Node {
    Node *right;
    Node *left;
    int level;
    int data;
public:
    explicit Node(int d, int l) {
        right = nullptr;
        left = nullptr;
        data = d;
        level = l;
    }

    void set_right(Node *nxt) {
        right = nxt;
    }

    void set_left(Node *nxt) {
        left = nxt;
    }

    int getData() {
        return data;
    }

    int getLevel() {
        return level;
    }

    void setData(int d) {
        data = d;
    }

    Node *get_left() {
        return left;
    }

    Node *get_right() {
        return right;
    }
};

Node *root = nullptr;

void display(Node *self, int dash) {//using pre order-recursion
    if (self != nullptr) {
        for (int i = 0; i < dash; ++i) {
            cout << " ";
        }
        cout << " |-(" << self->getData() <<" ("<<self->getLevel()<< "))" << endl;
        dash++;
        if (self->get_left() != nullptr)
            display(self->get_left(), dash);
        if (self->get_right() != nullptr)
            display(self->get_right(), dash);
    } else {
        cout << "Tree is empty" << endl;
    }
};
static Node *nextnode = new Node(10000, 100); //random big node
void findNextNode(Node *self) {

    if (self != nullptr) {
        if (self->get_left() != nullptr and self->get_right() != nullptr) {
            findNextNode(self->get_left());
            findNextNode(self->get_right());
        } else {
            if (nextnode->getLevel() > self->getLevel()) {
                nextnode = self;
            }
        }
    }
}

bool changeOccurred;

bool applyMaxProperty(Node *self) {
    if (self != nullptr) {
        if (self->get_left() != nullptr) {
            applyMaxProperty(self->get_left());
            if (self->getData() < self->get_left()->getData()) {
                changeOccurred = true;
                int temp = self->getData();
                self->setData(self->get_left()->getData());
                self->get_left()->setData(temp);
            }
        }
        if (self->get_right() != nullptr) {
            applyMaxProperty(self->get_right());
            if (self->getData() < self->get_right()->getData()) {
                changeOccurred = true;
                int temp = self->getData();
                self->setData(self->get_right()->getData());
                self->get_right()->setData(temp);
            }
        }
    }
}

bool applyMinProperty(Node *self) {
    if (self != nullptr) {
        if (self->get_left() != nullptr) {
            applyMinProperty(self->get_left());
            if (self->getData() > self->get_left()->getData()) {
                changeOccurred = true;
                int temp = self->getData();
                self->setData(self->get_left()->getData());
                self->get_left()->setData(temp);
            }
        }
        if (self->get_right() != nullptr) {
            applyMinProperty(self->get_right());
            if (self->getData() > self->get_right()->getData()) {
                changeOccurred = true;
                int temp = self->getData();
                self->setData(self->get_right()->getData());
                self->get_right()->setData(temp);
            }
        }
    }
}

void deleteTree(Node *self) {
    if (self != nullptr) {
        if (self->get_left() != nullptr)
            deleteTree(self->get_left());
        if (self->get_right() != nullptr)
            deleteTree(self->get_right());
        delete (self);
        self = nullptr;
    }
}

void createHeap(int op) {
    deleteTree(root);
    root = nullptr;
    int size = input.size();
    for (int i = 0; i < size; ++i) {
//        Node *ins = new Node(input[i]);
        if (root != nullptr) {
            findNextNode(root);
            Node *ins = new Node(input[i], nextnode->getLevel() + 1);
            if (nextnode->get_left() == nullptr) {
                nextnode->set_left(ins);
            } else if (nextnode->get_right() == nullptr) {
                nextnode->set_right(ins);
            } else {
                cout << "Something is wrong!" << nextnode->getData() << endl;
            }
            do {
                changeOccurred = false;
                if (op == 1)
                    applyMaxProperty(root);
                else if (op == 2)
                    applyMinProperty(root);
            } while (changeOccurred);
            delete nextnode;
            nextnode = new Node(10000, 100);
        } else {
            Node *ins = new Node(input[i], 0);
            root = ins;
        }
    }
    display(root, 0);
}

static Node *lastnode = new Node(10000, -1); //random big node
void findLastNode(Node *self) {
    if (self != nullptr) {
        if (self->get_left() != nullptr or self->get_right() != nullptr) {
            findLastNode(self->get_left());
            findLastNode(self->get_right());
        } else {
            if (lastnode->getLevel() <= self->getLevel()) {
                lastnode = self;
            }
        }
    }
}
Node *parentOflastnode= nullptr;
void findParent(Node* self,Node *child){
    if(self!= nullptr) {
        if (self->get_left() == child || self->get_right() == child) {
            parentOflastnode = self;
        } else {
            findParent(self->get_left(),child);
            findParent(self->get_right(),child);
        }
    }
}

void sort(int sortType){
    cout<<"Sorted array: ";
    for (int i = 0; i < input.size(); ++i){
        findLastNode(root);
        cout<<root->getData()<<" ";
        findParent(root,lastnode);

        //swap root and lastnode
        int temp = root->getData();
        root->setData(lastnode->getData());
        lastnode->setData(temp);

        //delete lastnode
        if(parentOflastnode->get_left()==lastnode) {
            delete parentOflastnode->get_left();
            parentOflastnode->set_left(nullptr);
        } else if (parentOflastnode->get_right()==lastnode){
            delete parentOflastnode->get_right();
            parentOflastnode->set_right(nullptr);
        }
        delete lastnode;
        lastnode = new Node(10000, -1);

        if(sortType==1){//desc
            do {
                changeOccurred = false;
                applyMaxProperty(root);
            } while (changeOccurred);
        } else{//asc
            do {
                changeOccurred = false;
                applyMinProperty(root);
            } while (changeOccurred);
        }
    }cout<<endl;

}

int main() {
    int op;
    int sortType = 0;
    cout << "1) Insert input" << endl;
    cout << "2) Max heap" << endl;
    cout << "3) Min head" << endl;
    cout << "4) Print tree" << endl;
    cout << "5) Sort" << endl;
    while (true) {
        cout << "Enter option: " << endl;
        cin >> op;
        if (op == 1) {
            int size;
            if (!input.empty()) {
                input.clear();
            }
            cout << "Enter the size of input: " << endl;
            cin >> size;
            for (int i = 0; i < size; ++i) {
                int temp;
                cout << "Enter value: " << endl;
                cin >> temp;
                input.push_back(temp);
            }
        } else if (op == 2) {
            if (!input.empty()) {
                sortType = 1;
                createHeap(sortType);//1 for max
            } else {
                cout << "Please insert inputs first using op 1";
            }
        } else if (op == 3) {
            if (!input.empty()) {
                sortType = 2;
                createHeap(sortType);//2 for min
            } else {
                cout << "Please insert inputs first using op 1";
            }
        } else if (op == 4) {
            display(root, 0);
        } else if (op == 5) {
            if (sortType != 0) {
                sort(sortType);
            } else {
                cout << "Perform option 2 or 3 first" << endl;
            }
        } else {
            break;
        }
    }
    return 0;
}
