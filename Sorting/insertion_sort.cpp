//
// Created by Nishit on 01-02-2020.
//
#include <iostream>
#include <vector>

using namespace std;

class Insertion {
    vector<int> data;
    int size;
    int pass;
    int steps;
public:
    Insertion() {
        size = 0;
        pass = 0;
        steps = 0;
    }

    void getData() {
        cout << "Enter the size of the array: ";
        cin >> size;
        cout << "Enter values: ";
        int temp;
        for (int i = 0; i < size; i++) {
            cin >> temp;
            data.push_back(temp);
        }
    }

    void display() {
        cout << "Pass " << pass << " and Steps " << steps << ": ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void insert(int ins, int num, int pivot) {
        int pivotData = data[pivot];
        for (int i = pivot; i > ins; --i) {
            data[i] = data[i - 1];
        }
        data[ins] = num;
    }

    void sort() {
        int pivot = 1;
        bool changeOccured;
        while (pivot < size) {
            for (int i = 0; i < pivot; i++) {
                steps++;
                if (data[pivot] < data[i]) {
                    insert(i, data[pivot], pivot);
                }
            }
            pivot++;
            pass++;
            display();
        }
    }
};

int main() {
    Insertion i;
    i.getData();
    i.display();
    i.sort();
    return 0;
}

