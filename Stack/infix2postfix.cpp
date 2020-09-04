//
// Created by Nishit on 06-02-2020.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Infix2Postfix {
    vector<char> memory;
    int top, size;
public:
    Infix2Postfix(int s) {
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
        return memory[top];
    }

    int getTopIndex() {
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
    string expression, newExpression;
    newExpression = "";
    cin >> expression;
    expression += ')';
    Infix2Postfix s(expression.length());
    s.push('(');
    for (char i : expression) {
        if ((i >= 65 and i <= 90) || (i >= 97 and i <= 122) || (i >= 48 and i <= 57)) {
            //all alphabets and numbers
            newExpression += i;
        } else {
            if (i == '(') {
                s.push(i);
            } else if (i == '+' || i == '-') {
                //remove existing and add it to new expression and push the + or -
                if (s.getTop() != '(') {
                    newExpression += s.getTop();
                    s.pop();
                }
                s.push(i);
            } else if (i == '*' or i == '/') {
                //remove existing and add it to new expression and push the * or /
                if (s.getTop() == '^') {
                    newExpression += s.getTop();
                    s.pop();
                }
                s.push(i);
            } else if (i == '^') {
                //remove existing and add it to new expression and push the ^
                if (s.getTop() == '^') {
                    newExpression += s.getTop();
                    s.pop();
                }
                s.push(i);
            } else if (i == ')') {
                while (s.getTop() != '(' and s.getTopIndex() >= 0) {
                    newExpression += s.getTop();
                    s.pop();
                }
                s.pop();
            }
        }
    }
    cout << newExpression << endl;
    return 0;
}
