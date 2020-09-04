//
// Created by Nishit on 05-02-2020.
//

#include <iostream>
#include <vector>

using namespace std;

class Stack {
    vector<int> memory;
    int top, size;
public:
    Stack() {
        size = 0;
        top = -1;
        cout << "Enter size of the stack: ";
        cin >> size;
        for (int i = 0; i < size; ++i) {
            memory.push_back(int(NULL));
        }
    }

    void push(int num) {
        if (top >= size - 1) {
            cout << "Stack overflow!" << endl;
        } else {
            top++;
            memory[top] = num;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Deleted value: " << memory[top] << endl;
            top--;
        }
    }

    void display() {
        for (int i = top; i >= 0; --i) {
            cout << i << "] " << memory[i] << "\n";
        }
        cout << endl;
    }

    void menu() {
        int option, num;
        do {
            cout << "1) Push" << endl;
            cout << "2) Pop" << endl;
            cout << "3) Display" << endl;
            cout << "4) Exit" << endl;
            cout << "Enter your option: ";
            cin >> option;
            if (option == 1) {
                cout << "Enter the number to push: ";
                cin >> num;
                push(num);
            } else if (option == 2) {
                pop();
            } else if (option == 3) {
                display();
            } else if (option == 4) {
                break;
            } else {
                cout << "Invalid input, Please try again!" << endl;
            }
        } while (true);
    }
};

int main() {
    Stack s;
    s.menu();
    return 0;
}

