//
// Created by Nishit on 17-01-2020.
//
#include <iostream>
#include <vector>

using namespace std;

class Quick {
public:
    vector<int> data;
    int size;
    int pass;
    int steps;

    Quick() {
        size = 0;
        pass = 0;
        steps = 0;
    }

    void display() {
        cout << "Pass " << pass << " and Steps " << steps << ": ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int sort(int start, int end) {

        //for testing
        if (pass > 20)
            return 0;
        //end


        int pivot = data[start];
        int first = start + 1;
        int last = end;
        bool change;
//        cout<<"pivot:"<<pivot<<" start: "<<start<<" end: "<<end<<" first: "<<first<<" last: "<<last<<endl;
//        cout<<"Before: ";
//        display();
        while (last >= first) {
            change = false;
            if (pivot >= data[first]) {
                first++;
                change = true;
            }
            if (data[last] > pivot) {
                last--;
                change = true;
            }
            if (!change) {
                int temp = data[first];
                data[first] = data[last];
                data[last] = temp;
            }
        }
        int temp = data[start];
        data[start] = data[last];
        data[last] = temp;
        pass++;
//        cout<<"pivot:"<<pivot<<" start: "<<start<<" end: "<<end<<" first: "<<first<<" last: "<<last<<endl;
//        cout<<"After: ";
        display();
        if (!(last >= end - 1) and !(last <= start + 1)) {
            cout << "Hello" << endl;
            if (last - start >= 2) {
                cout << "one" << endl;
                sort(start, last - 1);
            }
            if ((end + 1) - (last + 1) >= 2) {
                cout << "two" << endl;
                sort(last + 1, end);
            }
        } else {
            if (last >= end - 1 and last - start >= 2) {
                cout << "three" << endl;
                sort(start, last - 1);
            }
            if (last <= start + 1 and end - last >= 2) {
                cout << "fourth" << endl;
                sort(last + 1, end);
            }
        }

    }

    vector<int> getArrayFromRange(int start, int end) {
        vector<int> temp;
        for (int i = start; i < end; ++i) {
            temp.push_back(data[i]);
        }
        return temp;
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
};


int main() {
    Quick q;
    q.getData();
    q.sort(0, q.size - 1);
    return 0;
}
