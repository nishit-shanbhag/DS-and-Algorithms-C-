//
// Created by Nishit on 29/01/20.
//


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class DigitExtraction {
    vector<int> memory;
    vector<int> data;
    vector<int> digitExtract;
    int memorySize{}, inputSize{}, maxDigits;
public:
    DigitExtraction() {
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

        cout << "Enter no of digits to extract: ";
        int cde;
        cin >> cde;
        cout << "Enter the digits: ";
        int t;
        for (int j = 0; j < cde; ++j) {
            cin >> t;
            digitExtract.push_back(t);
        }

    }

    int putData() {
        if (inputSize > memorySize) {
            cout << "Not enough memory to allocate!" << endl;
            return 0;
        }
        vector<int> splitData;
        int num, idigit, finalno, loc;
        bool foundDigit;
        for (int i = 0; i < inputSize; ++i) {
            num = data[i];
            splitData.clear();
            //split the number
            idigit = findDigit(data[i]);
            for (int j = 0; j < idigit; ++j) {
                foundDigit = false;
                for (int k = 0; k < digitExtract.size(); ++k) {
                    if (j == digitExtract[k] - 1) {
                        foundDigit = true;
                    }
                }
                if (foundDigit)
                    splitData.push_back(num % 10);
                num /= 10;
            }

            // make the final no
            num = 0;
            for (int l = 0; l < splitData.size(); ++l) {
                num += splitData[l] * pow(10, l);
            }

            // find location and allocate
            loc = fromModuloGetLocation(num);
            memory[loc] = data[i];
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

    int reverse(int num) {
        int digit = findDigit(num);
        int d = digit;
        int counter = 1;
        for (int i = 0; i < digit; ++i) {
            num = num + (num % 10) * pow(10, digit + d - counter);
            num /= 10;
            d = findDigit(num) - digit;
            counter++;
        }
        return num;
    }
};

int main() {
    DigitExtraction lp;
    lp.putData();
    return 0;
}
