//
// Created by Nishit on 06-02-2020.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class BalancingBrackets {
    vector<int> memory;
    int top, size;
public:
    BalancingBrackets(int s) {
        size = 0;
        top = -1;
        size = s;
        for (int i = 0; i < size; ++i) {
            memory.push_back(int(NULL));
        }
    }

    int push(int num) {
        if (top >= size - 1) {
            return false;
        } else {
            top++;
            memory[top] = num;
            return true;
        }
    }

    bool pop() {
        if (top < 0) {
            return false;
        } else {
            top--;
            return true;
        }
    }

    void display() {
        for (int i = top; i >= 0; --i) {
            cout << i << "] " << memory[i] << "\n";
        }
        cout << endl;
    }

    int getTop() {
        return top;
    }

    int getFirst() {
        return memory[0];
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
    string expression;
    cin >> expression;
    BalancingBrackets s(expression.length());

    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '(') {
            if (!s.push(1)) {
                cout << "Invalid expression";
                return 0;
            }
        } else if (expression[i] == ')') {
            if (!s.pop()) {
                cout << "Invalid expression";
                return 0;
            }
        }
    }
    if (s.getTop() == -1)
        cout << "Correct expression!";
    else
        cout << "Invalid expression!";

    return 0;
}
s