//
// Created by Nishit on 29/01/20.
//


#include <iostream>
#include <vector>

using namespace std;

class ModuloDivision {
    vector<int> memory;
    vector<int> data;
    int memorySize, inputSize;
public:
    ModuloDivision() {
        cout << "Enter memory size: ";
        cin >> memorySize;
        for (int i = 0; i < memorySize; ++i) {
            memory.push_back('\0');
        }
        cout << "Enter Input size: ";
        cin >> inputSize;

        cout << "Enter Input data: ";
        int temp;
        for (int i = 0; i < inputSize; ++i) {
            cin >> temp;
            data.push_back(temp);
        }
    }

    int putData() {
        if (inputSize > memorySize) {
            cout << "Not enough memory to allocate!" << endl;
            return 0;
        }
        int modFunc;
        for (int i = 0; i < inputSize; ++i) {
            modFunc = data[i] % memorySize;
            while (memory[modFunc] != '\0') {
                modFunc++;
                if (modFunc > memorySize) {
                    modFunc = 0;
                }
            }
            memory[modFunc] = data[i];
        }
        displayMemory();
    }

    void displayMemory() {
        for (int i = 0; i < memorySize; ++i) {
            if (memory[i] != '\0')
                cout << i << " " << memory[i] << endl;
            else
                cout << i << " EMPTY" << endl;
        }
    }
};

int main() {
    ModuloDivision lp;
    lp.putData();
    return 0;
}
