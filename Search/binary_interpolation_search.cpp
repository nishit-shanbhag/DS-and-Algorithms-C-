//
// Created by Nishit on 23/01/20.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class BinarySearch {
    bool interpolation;
    vector<int> data;
    int size, key, comp;
public:
    BinarySearch() {
        size = 0;
        key = 0;
        comp = 0;
    }

    void getData() {
        cout << "Enter the size of the array: ";
        cin >> size;
        cout << "Enter values of the array: ";
        for (int i = 0; i < size; i++) {
            int temp;
            cin >> temp;
            data.push_back(temp);
        }
        char in;
        cout << "Use Interpolation Search?(Y/N): ";
        cin >> in;
        if (in == 'Y' or in == 'y')
            interpolation = true;
        else if (in == 'N' or in == 'n')
            interpolation = false;
        else {
            cout << "Incorrect input(Default set to No)" << endl;
            interpolation = false;
        }

    }

    void display() {
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
    }

    void search() {
        bool found = false;
        sort();
        cout << "Sorted array: ";
        display();
        cout << "\nEnter key value: ";
        cin >> key;
        int start = 0, end = data.size() - 1, mid;

        while (start <= end) {
            if (!interpolation)
                mid = (start + end) / 2;
            else
                mid = round(start + (end - start) * ((key - data[start]) / (data[end] - data[start])));
            cout << "Mid " << data[mid] << endl;
            comp++;
            if (key == data[mid]) {
                found = true;
                break;
            } else if (key < data[mid]) {
                end = mid - 1;
            } else if (key > data[mid]) {
                start = mid + 1;
            }
        }
        if (found or key == data[mid]) {
            cout << "Key found at Index: " << mid << " Position: " << mid + 1 << " (Total Comparisons: " << comp << ")";
        } else {
            cout << "Key doesnt exist in the array!" << " (Total Comparisons: " << comp << ")";
        }
    }

    void sort() {
        for (int i = 0; i < data.size(); ++i) {
            int min = 100000;
            int minIndex = 0;
            for (int k = i; k < data.size(); k++) {
                if (data[k] < min) {
                    min = data[k];
                    minIndex = k;
                }
            }
            int temp = data[i];
            data[i] = data[minIndex];
            data[minIndex] = temp;
        }
    }

};


int main() {
    BinarySearch i;
    i.getData();
    i.search();
    return 0;
}
