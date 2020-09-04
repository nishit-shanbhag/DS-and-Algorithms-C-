
//
// Created by nishit on 16-05-2020.
//

#include <iostream>
#include <vector>

using namespace std;

class Node_Queue {
    Node_Queue *next;
    string data;
public:
    Node_Queue(string d) {
        next = nullptr;
        data = d;
    }

    void setNext(Node_Queue *nxt) {
        next = nxt;
    }

    string getData() {
        return data;
    }

    void setData(int d) {
        data = d;
    }

    Node_Queue *getNext() {
        return next;
    }
};

Node_Queue *head_queue = nullptr;

//counting elements 12
int countElements() {
    Node_Queue *p = head_queue;
    int counter = 0;
    while (p != nullptr) {
        counter++;
        p = p->getNext();
    }
    return counter;
}

//insert at start 1
void insertAtStart(string data) {
    Node_Queue *ins = new Node_Queue(data);
    if (head_queue == nullptr) {
        head_queue = ins;
    } else {
        ins->setNext(head_queue);
        head_queue = ins;
    }
}

//insert at end 2
void insertAtEnd(string data) {
    Node_Queue *ins = new Node_Queue(data);
    if (head_queue == nullptr) {
        head_queue = ins;
    } else {
        Node_Queue *p = head_queue;
        while (p->getNext() != nullptr) {
            p = p->getNext();
        }
        p->setNext(ins);
    }
}



//delete from start 5
void deleteFromStart() {
    if (head_queue == nullptr) {
        cout << "Linked List is empty!" << endl;
    } else {
        Node_Queue *p = head_queue;
        head_queue = head_queue->getNext();
        delete p;
    }
}

//delete from end 6
void deleteFromEnd() {
    if (head_queue == nullptr) {
        cout << "Linked List is empty!" << endl;
    } else {
        Node_Queue *p = head_queue;
        Node_Queue *prev = p;
        while (p->getNext() != nullptr) {
            prev = p;
            p = p->getNext();
        }
        if (prev == p) {
            head_queue = nullptr;
        } else {
            prev->setNext(nullptr);
        }
        delete p;
    }
}

//print linked list 8
void printLinkedList() {
    Node_Queue *p = head_queue;
    if (head_queue == nullptr) {
        cout << "Linked list is Empty!" << endl;
    } else {
        while (p != nullptr) {
            cout << p->getData() << "->";
            p = p->getNext();
        }
        cout << "NULL" << endl;
    }
}

//search 11
void search(string d){
    if(head_queue== nullptr){
        cout<<"Linked list is empty!"<<endl;
    }else{
        Node_Queue *p = head_queue;
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
//--------------------------------------------------------------------

class Node_Stack {
    Node_Stack *next;
    string data;
public:
    Node_Stack(string d) {
        next = nullptr;
        data = d;
    }

    void setNext(Node_Stack *nxt) {
        next = nxt;
    }

    string getData() {
        return data;
    }

    int setData(string d) {
        data = d;
    }

    Node_Stack *getNext() {
        return next;
    }
};

Node_Stack *top = nullptr;
Node_Stack *head_stack = nullptr;

void Push(string d) {
    Node_Stack *pt = head_stack;
    Node_Stack *ins = new Node_Stack(d);
    if (top == nullptr) {
        head_stack = ins;
        top = ins;
    } else {
        top->setNext(ins);
        top = ins;
    }
}

void Pop() {
    Node_Stack *prev = head_stack;
    if(top==prev){
        delete top;
        top = nullptr;
        head_stack = nullptr;
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

void printStack() {
    if(top!= nullptr) {
        Node_Stack *pt = head_stack;
        while (pt != nullptr) {
            cout << pt->getData() << " ";
            pt = pt->getNext();
        }
        cout << endl;
    }else{
        cout<<"Stack is empty!"<<endl;
    }
}
//-----------------------------------------------------------

vector<vector <bool>> graph_matrix;
vector<string> nodes;

//Implement adjacency matrix creation
void create_adj_matrix(){
    int no_of_nodes;
    char op;
    cout<<"Enter the no of nodes:"<<endl;cin>>no_of_nodes;
    string temp;
    for (int i = 0; i < no_of_nodes; ++i) {
        cout<<"Enter the value of node "<<i<<" : "<<endl;cin>>temp;
        nodes.push_back(temp);
    }
    //takes connection from user and create a 2d array
    for (int j = 0; j < nodes.size(); ++j) {
        vector<bool> connection;
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[j]!=nodes[i]){
                cout<<"Is "<<nodes[j]<<" connected to "<<nodes[i]<<"?(y/n):"<<endl;
                cin>>op;
                connection.push_back( op == 'y' || op == 'Y' );
            }else{
                connection.push_back(false);
            }
        }
        graph_matrix.push_back(connection);
    }
}

void print_adj_matrix(){
    cout<<"========Adjacency Matrix========"<<endl;
    cout<<"   ";
    for (int k = 0; k < nodes.size(); ++k) {
        cout<<nodes[k]<<" ";
    }cout<<endl;
    for (int i = 0; i < graph_matrix.size(); ++i) {
        cout<<nodes[i]<<": ";
        for (int j = 0; j < graph_matrix[i].size(); ++j) {
            cout<<(graph_matrix[i][j]?"1":"0")<<" ";
        }cout<<endl;
    }
}

void breadthFirstSearch(){
    string root_node = nodes[0];
    int front = 1;
    int rear = 1;

    insertAtEnd(root_node);
    vector<string> checkedNodes;
    checkedNodes.push_back(root_node);
    cout<<"BFS sequence in the left:"<<endl;
    cout<<head_queue->getData()<<"| ";
    printLinkedList();
    while(front!=nodes.size()+1 or rear!=nodes.size()){
        //find index of head
        int index = 0;
        for (int i = 0; i < nodes.size(); ++i) {
            if(nodes[i]==head_queue->getData()){
                index=i;
                break;
            }
        }

        //find connections and insert into the queue and pop head
        for (int j = 0; j < graph_matrix[index].size(); ++j) {
            if(graph_matrix[index][j]){
//                checks in checked nodes
                bool foundInCheckedNodes=false;
                for (int i = 0; i < checkedNodes.size(); ++i) {
                    if(nodes[j]==checkedNodes[i]){
                        foundInCheckedNodes= true;
                        break;
                    }
                }
                if(not foundInCheckedNodes) {
                    insertAtEnd(nodes[j]);
                    checkedNodes.push_back(nodes[j]);
                    rear++;
                }
            }
        }
        deleteFromStart();
        if(head_queue!= nullptr)
            cout<<head_queue->getData()<<"| ";
        printLinkedList();
        front++;
    }cout<<endl;

}

void depthFirstSearch(){
    string root_node = nodes[0];

    Push(root_node);
    vector<string> checkedNodes;
    checkedNodes.push_back(root_node);
    cout<<"BFS sequence in the left:"<<endl;
    cout<<top->getData()<<"| ";
    printStack();
    while(top!= nullptr){
        //find index of head
        int index = 0;
        for (int i = 0; i < nodes.size(); ++i) {
            if(nodes[i]==top->getData()){
                index=i;
                break;
            }
        }
        Pop();
        //find connections and insert into the queue and pop head
        for (int j = 0; j < graph_matrix[index].size(); ++j) {
            if(graph_matrix[index][j]){
//                checks in checked nodes
                bool foundInCheckedNodes=false;
                for (int i = 0; i < checkedNodes.size(); ++i) {
                    if(nodes[j]==checkedNodes[i]){
                        foundInCheckedNodes= true;
                        break;
                    }
                }
                if(not foundInCheckedNodes) {
                    Push(nodes[j]);
                    checkedNodes.push_back(nodes[j]);
                }
            }
        }
        if(top!= nullptr)
            cout<<top->getData()<<"| ";
        printStack();
    }cout<<endl;
}

int main() {
    create_adj_matrix();
    print_adj_matrix();

    int op;


    while(1) {
        cout << "1) BFS" << endl;
        cout << "2) DFS" << endl;
        cout << "3) Exit" << endl;
        cout << "Enter the op: " << endl;
        cin >> op;
        if(op==1){
            breadthFirstSearch();
        }
        else if(op==2){
            depthFirstSearch();
        }
        else if(op==3)
            break;
    }
    return 0;
}

