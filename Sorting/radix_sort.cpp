//
// Created by Nishit on 17-01-2020.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Radix {
    vector<vector<int>> data;
    int size;
    int pass;
    int steps;
public:
    Radix() {
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
            vector<int> tempV;
            tempV.push_back(temp);
            data.push_back(tempV);
        }
    }

    void display() {
        cout << "Pass " << pass << " and Steps " << steps << ": ";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < data[i].size(); ++j) {
                cout << data[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }

    void sort() {
        // check max length
        int max = 0;
        int maxdigit = 0;
        for (int i = 0; i < size; i++) {
            if (data[i][0] > max) {
                max = data[i][0];
            }
        }
        while (max != 0) {
            max /= 10;
            maxdigit++;
        }
        //split the array into smaller arrays
        for (int j = 0; j < size; ++j) {
            for (int i = 1; i < maxdigit; ++i) {
                data[j].insert(data[j].begin() + 1, data[j][0] % 10);
                data[j][0] = data[j][0] / 10;
            }
        }
        //split the numbers into sections 0-9 depending on the digits and rearange
        for (int k = maxdigit - 1; k >= 0; --k) {
            vector<vector<vector<int>>> sorting;
            for (int l = 0; l < 10; ++l) {//fill empty vectors
                vector<vector<int>> temp;
                sorting.push_back(temp);
            }
            for (int i = 0; i < data.size(); ++i) {
                int d = data[i][k];
                sorting[d].push_back(data[i]);
            }
            //empty the vector
            data.erase(data.begin(), data.end());
            for (int j = 0; j < sorting.size(); ++j) {
                for (int i = 0; i < sorting[j].size(); ++i) {
            // cout<<sorting[j][i];
                    data.push_back(sorting[j][i]);
                }
            }
            pass++;
            display();
        }
    }
};

int main() {
    Radix r;
    r.getData();
    r.sort();
    return 0;
}