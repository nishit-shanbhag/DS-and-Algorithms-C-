#include <iostream>
#include <vector>

using namespace std;

class Selection {
    vector<int> data;
    int size;
    int pass;
    int steps;
public:
    Selection() {
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

    void sort() {
        for (int i = 0; i < data.size() - 1; ++i) {
            int min = data[i];
            int minIndex = i;
            for (int j = i + 1; j < data.size(); ++j) {
                if (data[j] < min) {
                    min = data[j];
                    minIndex = j;
                }
            }
            int temp = data[i];
            data[i] = data[minIndex];
            data[minIndex] = temp;
            display();
        }
    }
};

int main() {
    Selection s;
    s.getData();
    s.sort();
    return 0;
}
