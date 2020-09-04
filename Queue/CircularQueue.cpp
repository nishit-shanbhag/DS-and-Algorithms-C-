//
// Created by Nishit on 10-02-2020.
//
#include <iostream>
#include <vector>

using namespace std;

class Qcircular {
    int size, front, rear;
    vector<int> memory;
public:
    Qcircular() {
        front = 0;
        rear = -1;
        cout << "Enter the queue size: ";
        cin >> size;
        for (int i = 0; i < size; ++i) {
            memory.push_back(-1);
        }
    }

    void Enqueue() {
        if (rear - front >= size - 1) {
            cout << "Queue overflow!" << endl;
        } else {
            int ins;
            cout << "Enter the value to enqueue: ";
            cin >> ins;
            memory[(++rear) % size] = ins;
            cout << "rear: " << rear << endl;
        }
    }

    void Dequeue() {
        if (rear - front < 0) {
            cout << "Queue underflow!" << endl;
        } else {
            cout << "Dequeued " << memory[front % size] << endl;
            memory[front % size] = -1;
            front++;
            if (rear - front < 0) {
                front = 0;
                rear = -1;
            }
        }
    }

    void Display() {
        if (rear >= size) {
            for (int i = front; i < size; ++i) {
                cout << memory[i] << " ";
            }
            cout << '|';
            for (int i = 0; i <= rear % size; ++i) {
                cout << memory[i] << " ";
            }
        } else {
            for (int i = front; i <= rear; ++i) {
                cout << memory[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    Qcircular q;
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
