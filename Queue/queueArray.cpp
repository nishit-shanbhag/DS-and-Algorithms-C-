//
// Created by Nishit on 10-02-2020.
//
#include <iostream>
#include <vector>

using namespace std;

class Qnormal {
    int size, front, rear;
    vector<int> memory;
public:
    Qnormal() {
        front = 0;
        rear = -1;
        cout << "Enter the queue size: ";
        cin >> size;
        for (int i = 0; i < size; ++i) {
            memory.push_back(-1);
        }
    }

    void Enqueue() {
        if (rear == size - 1) {
            cout << "Queue overflow!" << endl;
        } else {
            int ins;
            cout << "Enter the value to enqueue: ";
            cin >> ins;
            memory[++rear] = ins;
        }
    }

    void Dequeue() {
        if (rear < front) {
            cout << "Queue underflow!" << endl;
        } else {
            cout << "Dequeued " << memory[front++] << endl;
        }
    }

    void Display() {
        for (int i = front; i <= rear; ++i) {
            cout << memory[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Qnormal q;
    int op;
    do {
        cout << "1) Enqueue" << endl;
        cout << "2) Dequeue" << endl;
        cout << "3) Display" << endl;
        cout << "Enter the option: ";
        cin >> op;
        if (op == 1) {
            q.Enqueue();
        } else if (op == 2) {
            q.Dequeue();
        } else if (op == 3) {
            q.Display();
        } else if (op == 4) {
            break;
        }
    } while (1);
    return 0;
}
