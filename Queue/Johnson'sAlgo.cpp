//
// Created by Nishit on 10-02-2020.
//
#include <iostream>
#include <vector>

using namespace std;
vector<int> memory;

class Queue_JohnsonAlgo {
    int size, front1, rear1, front2, rear2;

public:
    Queue_JohnsonAlgo(int size) {
        front1 = 0;
        rear1 = -1;
        for (int i = 0; i < size; ++i) {
            memory.push_back(-1);
        }
        front2 = memory.size() - 1;
        rear2 = memory.size();
    }

    void EnqueueLeft(int ins) {
        if (rear1 == rear2 - 1) {
            cout << "Queue Overflow!" << endl;
        } else {
            memory[++rear1] = ins;
        }
    }

    void DequeueLeft() {
        if (front1 == rear2) {
            cout << "Queue is empty from the Left please try to dequeue from right!" << endl;
        } else if (rear1 < front1) {
            cout << "Underload!" << endl;
        } else {
            cout << "Dequeued " << memory[front1] << endl;
            memory[front1] = -1;
            front1++;
        }
    }

    void EnqueueRight(int ins) {
        if (rear1 == rear2 - 1) {
            cout << "Queue overflow!" << endl;
        } else {
            memory[--rear2] = ins;
        }
    }

    void DequeueRight() {
        if (front2 == rear1) {
            cout << "Queue is empty from the right please try to dequeue from left!" << endl;
        } else if (rear2 > front2) {
            cout << "Underload!" << endl << "Front1: " << front1 << "Rear1: " << rear1 << " Front2: " << front2
                 << "Rear2: " << rear2 << endl;
        } else {
            cout << "Dequeued " << memory[front2] << endl;
            memory[front2] = -1;
            front2--;
        }
    }

    void Display() {
        for (int i = 0; i < memory.size(); ++i) {
            cout << memory[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    vector<vector<int>> input;
    vector<vector<int>> copy;
    int jobCount;
    cout << "Enter job count: ";
    cin >> jobCount;
    Queue_JohnsonAlgo q(jobCount);
    //input
    for (int i = 0; i < jobCount; ++i) {
        vector<int> t;
        int temp;
        cout << "Enter job name: ";
        cin >> temp;
        t.push_back(temp);
        cout << "Enter Burst(Machine 1): ";
        cin >> temp;
        t.push_back(temp);
        cout << "Enter Burst(Machine 2): ";
        cin >> temp;
        t.push_back(temp);
        input.push_back(t);
    }
    copy = input;

    for (int l = 0; l < jobCount; ++l) {
        int min = 10000, minPId;
        vector<int> pid;
        vector<int> m1_Or_m2;
        // find smallest in first & second
        for (int k = 0; k < copy.size(); ++k) {
            if (copy[k][1] < min) {
                min = copy[k][1];
                minPId = copy[k][0];
            }
            if (copy[k][2] < min) {
                min = copy[k][2];
                minPId = copy[k][0];
            }
        }
        //find index of all matching the min
        for (int k = 0; k < copy.size(); ++k) {
            if (copy[k][1] == min) {
                pid.push_back(copy[k][0]);
                m1_Or_m2.push_back(0);
            }
            if (copy[k][2] == min) {
                pid.push_back(copy[k][0]);
                m1_Or_m2.push_back(1);
            }
        }
        //enqueue and remove from vector
        bool start = true;
        for (int i = 0; i < pid.size(); ++i) {
            //if 0 then left or else right
            start = m1_Or_m2[i] == 0;
            if (start) {
                q.EnqueueLeft(pid[i]);
                //remove
                for (int j = 0; j < copy.size(); ++j) {
                    if (copy[j][0] == pid[i]) {
                        copy.erase(copy.begin() + j);
                        break;
                    }
                }
                start = false;
            } else {
                q.EnqueueRight(pid[i]);
                //remove
                for (int j = 0; j < copy.size(); ++j) {
                    if (copy[j][0] == pid[i]) {
                        copy.erase(copy.begin() + j);
                        break;
                    }
                }
                start = true;
            }
        }
    }

    //display list
    cout << endl;
    q.Display();
    cout << "Process" << "\t|\t" << "Machine 1" << "\t|\t" << "Machine 2" << endl;
    cout << "-----------------------------------------------------" << endl;
    for (int n = 0; n < input.size(); ++n) {
        cout << "P" << input[n][0] << "\t\t|\t\t" << input[n][1] << "\t\t|\t\t" << input[n][2] << endl;
    }

    //print the completion time
    int time1 = 0, time2 = 0;
    for (int m = 0; m < memory.size(); ++m) {
        cout << "Job: " << input[memory[m] - 1][0] << " ";
        time1 += input[memory[m] - 1][1];
        cout << "Machine 1(completion time): " << time1 << " ";
        if (time2 < time1)
            time2 = time1;

        time2 += input[memory[m] - 1][2];
        cout << "Machine 2(completion time): " << time2 << " " << endl;
    }
    cout << "TOTAL TIME: " << time2 << endl;

    return 0;
}
