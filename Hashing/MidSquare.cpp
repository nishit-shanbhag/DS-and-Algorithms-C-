//
// Created by Nishit on 29/01/20.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MidSquare {
    vector<int> memory;
    vector<int> data;
    int memorySize, inputSize, maxDigits;
public:
    MidSquare() {
        cout << "Enter memory size: ";
        cin >> memorySize;
        for (int i = 0; i < memorySize; ++i) {
            memory.push_back(-1);
        }
        cout << "Enter Input size: ";
        cin >> inputSize;

        cout << "Enter Input data: ";
        int temp;
        for (int i = 0; i < inputSize; ++i) {
            cin >> temp;
            data.push_back(temp);
        }
        maxDigits = findDigit(memorySize - 1);
    }

    int putData() {
        if (inputSize > memorySize) {
            cout << "Not enough memory to allocate!" << endl;
            return 0;
        }

        int squareFunc, squareDigits, loc;
        for (int i = 0; i < inputSize; ++i) {
            squareFunc = data[i] * data[i];
            squareDigits = findDigit(squareFunc);
            if (squareDigits <= maxDigits) {
                loc = fromModuloGetLocation(squareFunc);
                memory[loc] = data[i];
            } else {
                while (squareDigits > 2) {
                    squareFunc = shrink(squareFunc);
                    squareDigits = findDigit(squareFunc);
                }
                loc = fromModuloGetLocation(squareFunc);
                memory[loc] = data[i];
            }
        }
        displayMemory();
    }

    void displayMemory() {
        for (int i = 0; i < memorySize; ++i) {
            if (memory[i] != -1)
                cout << i << " " << memory[i] << endl;
            else
                cout << i << " EMPTY" << endl;
        }
    }

    int findDigit(int num) {
        int digits = 0;

        while (num > 0) {
            num /= 10;
            digits++;
        }
        return digits;
    }

    int fromModuloGetLocation(int num) {
        int modFunc = num;
        if (num > memorySize)
            modFunc = num % memorySize;

        while (memory[modFunc] != -1) {
            modFunc++;
            if (modFunc > memorySize) {
                modFunc = 0;
            }
        }
        return modFunc;
    }

    int shrink(int num) {
        int d = findDigit(num);
        num = num / 10;
        num = num % int(pow(10, d - 2));
        return num;
    }
};

int main() {
    MidSquare lp;
    lp.putData();
    return 0;
}



