//
// Created by Nishit on 17-01-2020.
//
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Shell {
    vector<int> data;
    int size;
    int pass;
    int steps;
public:
    Shell() {
        size = 0;
        pass = 0;
        steps = 0;
    }

    void getData() {
        cout << "Enter the size of the array";
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

    void sortShell() {
        int inc = (data.size() / 2);

        while (inc >= 1) {
            //print the inc levels
            /*
            for (int i = 0; i < inc; ++i) {
                for (int j = i; j < data.size(); j+=inc) {
                    //printing - remove later
cout<<data[j]<<" ";
                }
                cout<<endl;
            }*/
            for (int i = 0; i < inc; ++i) {
                for (int j = i; j < data.size() - inc; j += inc) {
                    int min = 100000;
                    int minIndex = 0;
                    for (int k = j; k < data.size(); k += inc) {
                        if (data[k] < min) {
                            min = data[k];
                            minIndex = k;
                            steps++;
                        }
                    }
                    int temp = data[j];
                    data[j] = data[minIndex];
                    data[minIndex] = temp;
                }
            }
            inc /= 2;
            pass++;
            display();
        }
    }

};

int main() {
    Shell s;
    s.getData();
    s.sortShell();
    return 0;
}

