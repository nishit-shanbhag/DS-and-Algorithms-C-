#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class FoldBoundary {
    vector<int> memory;
    vector<int> data;
    int memorySize, inputSize, maxDigits;
public:
    FoldBoundary() {
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
        int num, sum, loc;
        for (int i = 0; i < inputSize; ++i) {
            num = data[i];
            if (num > memorySize - 1) {
                sum = 0;
                //first section in reverse
                sum += reverse(num % int(pow(10, maxDigits)));
                num /= int(pow(10, maxDigits));
                while (findDigit(num) > maxDigits) {
                    sum += num % int(pow(10, maxDigits));
                    num /= int(pow(10, maxDigits));
                }
                int missingDigits = maxDigits - findDigit(num % int(pow(10, maxDigits)));
                sum += reverse(num % int(pow(10, maxDigits))) * pow(10, missingDigits);
                num /= int(pow(10, maxDigits));
                if (sum <= memorySize - 1) {
                    loc = fromModuloGetLocation(sum);
                    memory[loc] = data[i];
                } else {
                    loc = fromModuloGetLocation(sum % int(pow(10, maxDigits)));
                    memory[loc] = data[i];
                }
            } else {
                loc = fromModuloGetLocation(num);
                memory[loc] = data[i];
            }

        }
        displayMemoryWEmpty();
    }

    void displayMemory() {
        for (int i = 0; i < memorySize; ++i) {
            if (memory[i] != -1)
                cout << i << " " << memory[i] << endl;
            else
                cout << i << " EMPTY" << endl;
        }
    }

    void displayMemoryWEmpty() {
        for (int i = 0; i < memorySize; ++i) {
            if (memory[i] != -1)
                cout << i << " " << memory[i] << endl;
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
        if (num > memorySize)modFunc = num % memorySize;

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
    FoldBoundary lp;
    lp.putData();
    return 0;
}
