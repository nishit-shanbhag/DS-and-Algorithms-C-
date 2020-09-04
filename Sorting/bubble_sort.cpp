#include <iostream>

using namespace std;

class bubbleSort {
    int data[1000];
    int pass;
    int size;
    int steps;
public:
    bubbleSort() {
        pass = 0;
        size = 0;
        steps = 0;
    }

    void getData() {
        cout << "Enter the size of array:";
        cin >> size;
        cout << "Enter values: " << endl;
        for (int i = 0; i < size; i++) {
            cin >> data[i];
        }
    }

    void sort() {
        int upperLimit = size;
        displayData();
        bool changeOccured;
        for (int i = 1; i <= size; i++) {
            changeOccured = false;
            for (int j = 0; j < upperLimit - i; j++) {
                if (data[j] > data[j + 1]) {
                    changeOccured = true;
                    steps++;
                    //swap
                    int temp;
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
            if (changeOccured) {
                pass++;
                displayData();
            } else {
                if (pass > 0)
                    cout << "Sorted! in " << steps << " Steps and " << pass << "Passes" << endl;
                else
                    cout << "It was already sorted!";
                break;
            }
        }
    }

    void displayData() {
        cout << "Pass " << pass << ": ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    bubbleSort b;
    b.getData();
    b.sort();
    return 0;
}

