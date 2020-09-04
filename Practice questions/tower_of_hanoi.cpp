//
// Created by nishit on 07-05-2020.
//

#include <iostream>
#include <cmath>

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

class Stack{
    Node *top;
    Node *head;
public:
    Stack(){
        top=nullptr;
        head=nullptr;
    }
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
        }
    }

    int getTop() {
        if(top!=nullptr)
            return top->getData();
        else{
            return -1;
        }
    }

    void printLinkedList() {
        cout<<"|";
        if(top!= nullptr) {
            Node *pt = head;
            while (pt != nullptr) {
                cout <<"-"<< pt->getData();
                pt = pt->getNext();
            }
        }
        cout << endl;
    }
};
Stack tower1;
Stack tower2;
Stack tower3;

void printMove(int move){

    cout<<"-----------------------------------------"<<endl;

    cout << "Move: " << move << endl;
    cout<<"A";
    tower1.printLinkedList();
    cout<<"B";
    tower2.printLinkedList();
    cout<<"C";
    tower3.printLinkedList();
}

int main() {

    int disks;
    int no_of_moves;
    cout<<"Insert no of disks: "<<endl;
    cin>>disks;
    no_of_moves = pow(2,disks)-1;
    cout<<"No of moves expected: "<<no_of_moves<<endl;
    //insert initial disks in first tower
    for (int i = disks-1; i >=0; --i) {
        tower1.Push(i);
    }
    cout<<"--------------Initial state-------------"<<endl;
    printMove(0);
    int temp;
    if(disks%2==0) {
            int move=1;
            while(move<=no_of_moves) {

                // make the legal move between pegs A and B (in either direction)
                if(tower1.getTop()==-1){
                    temp = tower2.getTop();
                    tower1.Push(temp);
                    tower2.Pop();
                }else if(tower2.getTop()==-1){
                    temp = tower1.getTop();
                    tower2.Push(temp);
                    tower1.Pop();
                }
                else {
                    if (tower1.getTop() < tower2.getTop()) {
                        temp = tower1.getTop();
                        tower2.Push(temp);
                        tower1.Pop();
                    } else if (tower1.getTop() > tower2.getTop()) {
                        temp = tower2.getTop();
                        tower1.Push(temp);
                        tower2.Pop();
                    }
                }


                printMove(move);
                move++;
                if(move<=no_of_moves) {
                    //make the legal move between pegs A and C (in either direction)
                    if(tower1.getTop()==-1){
                        temp = tower3.getTop();
                        tower1.Push(temp);
                        tower3.Pop();
                    }else if(tower3.getTop()==-1){
                        temp = tower1.getTop();
                        tower3.Push(temp);
                        tower1.Pop();
                    }
                    else {
                        if (tower1.getTop() < tower3.getTop()) {
                            temp = tower1.getTop();
                            tower3.Push(temp);
                            tower1.Pop();
                        } else if (tower1.getTop() > tower3.getTop()) {
                            temp = tower3.getTop();
                            tower1.Push(temp);
                            tower3.Pop();
                        }
                    }
                    printMove(move);
                    move++;
                }
                if(move<=no_of_moves) {
                    //make the legal move between pegs B and C (in either direction)
                    if(tower2.getTop()==-1){
                        temp = tower3.getTop();
                        tower2.Push(temp);
                        tower3.Pop();
                    }else if(tower3.getTop()==-1){
                        temp = tower2.getTop();
                        tower3.Push(temp);
                        tower2.Pop();
                    }
                    else {
                        if (tower2.getTop() < tower3.getTop()) {
                            temp = tower2.getTop();
                            tower3.Push(temp);
                            tower2.Pop();
                        } else if (tower2.getTop() > tower3.getTop()) {
                            temp = tower3.getTop();
                            tower2.Push(temp);
                            tower3.Pop();
                        }
                    }
                    printMove(move);
                    move++;
                }
            }
    } else{//odd
        int move=1;
        while(move<=no_of_moves) {
            //make the legal move between pegs A and C (in either direction)
            if(tower1.getTop()==-1){
                temp = tower3.getTop();
                tower1.Push(temp);
                tower3.Pop();
            }else if(tower3.getTop()==-1){
                temp = tower1.getTop();
                tower3.Push(temp);
                tower1.Pop();
            }
            else {
                if (tower1.getTop() < tower3.getTop()) {
                    temp = tower1.getTop();
                    tower3.Push(temp);
                    tower1.Pop();
                } else if (tower1.getTop() > tower3.getTop()) {
                    temp = tower3.getTop();
                    tower1.Push(temp);
                    tower3.Pop();
                }
            }
            printMove(move);
            move++;

            if(move<=no_of_moves) {

                // make the legal move between pegs A and B (in either direction)
                if(tower1.getTop()==-1){
                    temp = tower2.getTop();
                    tower1.Push(temp);
                    tower2.Pop();
                }else if(tower2.getTop()==-1){
                    temp = tower1.getTop();
                    tower2.Push(temp);
                    tower1.Pop();
                }
                else {
                    if (tower1.getTop() < tower2.getTop()) {
                        temp = tower1.getTop();
                        tower2.Push(temp);
                        tower1.Pop();
                    } else if (tower1.getTop() > tower2.getTop()) {
                        temp = tower2.getTop();
                        tower1.Push(temp);
                        tower2.Pop();
                    }
                }
                printMove(move);
                move++;
            }
            if(move<=no_of_moves) {
                //make the legal move between pegs B and C (in either direction)
                if(tower2.getTop()==-1){
                    temp = tower3.getTop();
                    tower2.Push(temp);
                    tower3.Pop();
                }else if(tower3.getTop()==-1){
                    temp = tower2.getTop();
                    tower3.Push(temp);
                    tower2.Pop();
                }
                else {
                    if (tower2.getTop() < tower3.getTop()) {
                        temp = tower2.getTop();
                        tower3.Push(temp);
                        tower2.Pop();
                    } else if (tower2.getTop() > tower3.getTop()) {
                        temp = tower3.getTop();
                        tower2.Push(temp);
                        tower3.Pop();
                    }
                }
                printMove(move);
                move++;
            }
        }

    }


    return 0;
}
