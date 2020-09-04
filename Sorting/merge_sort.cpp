//
// Created by nishi on 12-03-2020.
//
#include <iostream>
#include <fstream>
#include <bits/unique_ptr.h>

using namespace std;

int main(){
    ifstream bigFile("data.txt");
    int len = 10000;
    int memory = 10* sizeof(int);

    for (int i = 0; i < len/10; ++i) {
        unique_ptr<char[]> buffer(new char[memory]);
        while(bigFile){
            bigFile.read(buffer.get(),memory);
        }
        ofstream file;
        string fname = to_string(i)+".txt";
        file.open(fname);
        for (int j = 0; j < 10; ++j) {
            file<<buffer[j];
        }
        file.close();
    }

    return 0;
}
