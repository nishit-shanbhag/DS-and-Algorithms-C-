//
// Created by Nishit on 10-02-2020.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Node;

int time = 0;
Node *head = nullptr;
Node *last = nullptr;

vector<vector<int>> input;
vector<vector<int>> copyInput;
vector<vector<int>> output;
vector<vector<int>> responseTime;

class Node {
    Node *next;
    int name;
    int arrivalTime;
    int burstTime;
public:
    Node(int n, int at, int bt) {
        next = head;
        name = n;
        arrivalTime = at;
        burstTime = bt;
    }

    void setNext(Node *nxt) {
        next = nxt;
    }

    int getPSN() {
        return name;
    }

    int getBurst() {
        return burstTime;
    }

    int getArrival() {
        return arrivalTime;
    }

    void setBurst(int burst) {
        burstTime = burst;
    }

    Node *getNext() {
        return next;
    }

    void getJobDetail() {
        cout << "P" << name << " Burst Time: " << burstTime << endl;
    }
};

void deleteLast() {
    Node *pt = head;
    Node *pre = pt;
    bool found = false;
    while (pt != last) {
        found = true;
        pre = pt;
        pt = pt->getNext();
    }
    pre->setNext(head);
    last = pre;
    delete pt;
}

void deleteFirst() {
    Node *pt = head;
    if (pt->getNext() != head) {
        Node *nxt = pt->getNext();
        delete head;
        head = nxt;
        last->setNext(head);
    } else {
        head = nullptr;
        last = nullptr;
    }
}

void insertNext(int n, int at, int bt) {
    Node *pt = head;
    Node *ins = new Node(n, at, bt);
    if (pt != nullptr) {
        while (pt != last) {
            pt = pt->getNext();
        }
        pt->setNext(ins);
        last = ins;
        ins->setNext(head);
    } else {
        head = ins;
        last = head;
    }
}

void insertNext(Node *i) {
    Node *pt = head;
    Node *ins = i;
    if (head != nullptr) {
        while (pt != last) {
            pt = pt->getNext();
        }
        pt->setNext(ins);
        last = ins;
        ins->setNext(head);
    } else {
        head = ins;
        last = head;
    }
}

int calculateTotalBurst() {
    int totalBurst = 0;
    Node *pt = head;
    if (pt != last) {
        while (pt->getNext() != head) {
            totalBurst += pt->getBurst();
            pt = pt->getNext();
        }
        totalBurst += pt->getBurst();
    } else
        totalBurst += pt->getBurst();
    return totalBurst;
}

void printLinkedList() {
    Node *pt = head;
    cout << endl;
    if (pt != last) {
        while (pt->getNext() != head) {
            cout << pt->getPSN() << " ";
            pt = pt->getNext();
        }
        cout << pt->getPSN() << endl;
    } else
        cout << pt->getPSN() << endl;
}

void getJobs() {
    //add all the jobs that have arrived to linked list
    for (int i = 0; i < input.size(); ++i) {
        if (input[i][1] <= time) {
            insertNext(input[i][0], input[i][1], input[i][2]);
            input.erase(input.begin() + i);
            i--;
        }
    }
}

int getOriginalBurst(Node *pt) {
    int bt = 0;
    for (int j = 0; j < copyInput.size(); ++j) {
        if (copyInput[j][0] == pt->getPSN()) {
            bt = copyInput[j][2];
            break;
        }
    }
    return bt;
}

int main() {
    int size, tq, totalBurst = 0;
    cout << "Enter job count: ";
    cin >> size;
    cout << "Enter Time quantum: ";
    cin >> tq;
    for (int i = 0; i < size; ++i) {
        vector<int> temp;
        int jname;
        int at, bt;
        totalBurst += bt;
        cout << "Enter Process Name: ";
        cin >> jname;
        cout << "Enter arrival Time: ";
        cin >> at;
        cout << "Enter Burst Time: ";
        cin >> bt;
        temp.push_back(jname);
        temp.push_back(at);
        temp.push_back(bt);
        input.push_back(temp);
        cout << endl;
    }
    copyInput = input;
    getJobs();
    Node *pt;
    cout << "---------Time: " << time << "----------" << endl;
    while (calculateTotalBurst() > 0) {
        pt = head;
        for (int i = 0; i < tq; ++i) {
            if (pt->getBurst() > 0) {
                //calculate response time if the process is new
                if (pt->getBurst() == getOriginalBurst(pt)) {
                    //this job arrived first time
                    vector<int> t;
                    t.push_back(pt->getPSN());
                    t.push_back(time - pt->getArrival());//calculate response time
                    responseTime.push_back(t);
                }
                pt->setBurst(pt->getBurst() - 1);
                pt->getJobDetail();
                time++;
                getJobs();
                cout << "---------Time: " << time << "----------" << endl;

                if (pt->getBurst() == 0) {//calculates and stores CT TAT WT
                    vector<int> t;
                    t.push_back(pt->getPSN()); //process name
                    t.push_back(time); //completion time
                    t.push_back(time - pt->getArrival()); //Turn around time

                    //get burst time from copy of input array
                    int bt = getOriginalBurst(pt);

                    t.push_back((time - pt->getArrival()) - bt); //get waiting time
                    output.push_back(t);
                }
            } else {
                getJobs();
            }
        }
        if (head->getNext() != head) {
            head = head->getNext();
            insertNext(pt);
        } else {
            deleteFirst();
        }
    }
    cout << "\nPno\t|\t" << "AT\t|\t" << "BT\t|\t" << "CT\t|\t" << "TAT\t|\t" << "WT\t|\t" << "RspT\t|\t" << endl;
    cout << "--------------------------------------------------------" << endl;
    double avgTAT = 0, avgWT = 0, avgRspT = 0;
    for (int j = 0; j < copyInput.size(); ++j) {
        int outputIndex;
        int responseIndex;
        for (int i = 0; i < output.size(); ++i) {
            if (output[i][0] == copyInput[j][0]) {
                outputIndex = i;
            }
            if (responseTime[i][0] == copyInput[j][0]) {
                responseIndex = i;
            }
        }
        cout << copyInput[j][0] << "\t|\t" << copyInput[j][1] << "\t|\t" << copyInput[j][2] << "\t|\t"
             << output[outputIndex][1] << "\t|\t" << output[outputIndex][2] << "\t|\t" << output[outputIndex][3]
             << "\t|\t" << responseTime[responseIndex][1] << "\t\t|\t" << endl;
        avgTAT += output[outputIndex][2];
        avgWT += output[outputIndex][3];
        avgRspT += responseTime[responseIndex][1];
    }
    cout << "Average TurnAround Time: " << avgTAT / size << endl;
    cout << "Average Waiting Time: " << avgWT / size << endl;
    cout << "Average Response Time: " << avgRspT / size << endl;
    return 0;
}
