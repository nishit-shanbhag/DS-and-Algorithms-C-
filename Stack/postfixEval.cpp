//
// Created by Nishit on 05-02-2020.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class PostFix {
    vector<int> memory;
    int top, size;
public:
    PostFix(int s) {
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
};

int main() {
    string expression;
    cin >> expression;
    PostFix s(expression.length());
    expression += ')';
//    cout<<expression;

    bool wasOperator = false;
    int isNum = 0;
    int finalNum = 0;
    string tempNum;
    for (int i = 0; i < expression.length(); ++i) {
        if (int(expression[i]) >= 48 and int(expression[i]) <= 57) {
            tempNum += expression[i];
            wasOperator = false;
        } else {

            //calculate char num to int num
            int count = 0;
            for (int j = tempNum.length() - 1; j >= 0; --j) {
                finalNum += (tempNum[j] - 48) * int(pow(10, count++));
            }
            //check the char
            int num1, num2;
            if (expression[i] == '+') {
                if (wasOperator or isNum > 2) {
                    cout << "Incorrect expression!";
                    break;
                }
                isNum = 0;
                num1 = s.getTop();
                s.pop();
                num2 = s.getTop();
                s.pop();
                s.push(num2 + num1);
                wasOperator = true;
            } else if (expression[i] == '-') {
                if (wasOperator) {
                    cout << "Incorrect expression!";
                    break;
                }
                num1 = s.getTop();
                s.pop();
                num2 = s.getTop();
                s.pop();
                s.push(num2 - num1);
                wasOperator = true;
            } else if (expression[i] == '*') {
                if (wasOperator) {
                    cout << "Incorrect expression!";
                    break;
                }
                num1 = s.getTop();
                s.pop();
                num2 = s.getTop();
                s.pop();
                s.push(num2 * num1);
                wasOperator = true;
            } else if (expression[i] == '/') {
                if (wasOperator) {
                    cout << "Incorrect expression!";
                    break;
                }
                if (s.getTopIndex() > 0) {
                    num1 = s.getTop();
                    s.pop();
                    num2 = s.getTop();
                    s.pop();
                    s.push(num2 / num1);
                } else {
                    cout << "Not enough numbers in stacks!";
                }
                wasOperator = true;
            } else if (expression[i] == ')') {
                cout << s.getFirst();
            } else {
                if (!wasOperator) {
                    if (!s.push(finalNum)) {
                        cout << "Wrong expression" << endl;
                    }
                }
            }
            if (s.getTopIndex() + 1 > 2) {
                cout << "More than 2 numbers!" << endl;
                return 0;
            }
            tempNum = "";
            finalNum = 0;
        }
    }
    return 0;
}
