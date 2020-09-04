//
// Created by Nishit on 10-02-2020.
//
#include <iostream>
#include <vector>

using namespace std;

class Queue_DoubleEnded {
    int size, front1, rear1, front2, rear2;
    vector<int> memory;
public:
    Queue_DoubleEnded() {
        front1 = 0;
        rear1 = -1;
        cout << "Enter the queue size: ";
        cin >> size;
        for (int i = 0; i < size; ++i) {
            memory.push_back(-1);
        }
        front2 = memory.size() - 1;
        rear2 = memory.size();
    }

    void EnqueueLeft() {
        if (rear1 == rear2 - 1) {
            cout << "Queue Overflow!" << endl;
        } else {
            int ins;
            cout << "Enter the value to enqueue: ";
            cin >> ins;
            memory[++rear1] = ins;
        }
    }

    void DequeueLeft() {
        if (front1 == rear2) {
            cout << "Queue is empty from the Left please try to dequeue from right!" << endl;
        } else if (rear1 < front1) {
            cout << "Underload!" << endl;
        } else {
            cout << "Dequeued " << memory[front1] << endl;
            memory[front1] = -1;
            front1++;
        }
    }

    void EnqueueRight() {
        if (rear1 == rear2 - 1) {
            cout << "Queue overflow!" << endl;
        } else {
            int ins;
            cout << "Enter the value to enqueue: ";
            cin >> ins;
            memory[--rear2] = ins;
        }
    }

    void DequeueRight() {
        if (front2 == rear1) {
            cout << "Queue is empty from the right please try to dequeue from left!" << endl;
        } else if (rear2 > front2) {
            cout << "Underload!" << endl << "Front1: " << front1 << "Rear1: " << rear1 << " Front2: " << front2
                 << "Rear2: " << rear2 << endl;
        } else {
            cout << "Dequeued " << memory[front2] << endl;
            memory[front2] = -1;
            front2--;
        }
    }

    void Display() {
        cout << "Front1: " << front1 << "Rear1: " << rear1 << " Front2: " << front2 << "Rear2: " << rear2 << endl;
        for (int i = 0; i < memory.size(); ++i) {
            cout << memory[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue_DoubleEnded q;
    int op;
    do {
        cout << "1) Enqueue Left" << endl;
        cout << "2) Dequeue Left" << endl;
        cout << "3) Enqueue Right" << endl;
        cout << "4) Dequeue Right" << endl;
        cout << "5) Display" << endl;
        cout << "6) Exit" << endl;
        cout << "Enter the option: ";
        cin >> op;
        if (op == 1) {
            q.EnqueueLeft();
        } else if (op == 2) {
            q.DequeueLeft();
        } else if (op == 3) {
            q.EnqueueRight();
        } else if (op == 4) {
            q.DequeueRight();
        } else if (op == 5) {
            q.Display();
        } else if (op == 6) {
            break;
        }
    } while (1);
    return 0;
}
