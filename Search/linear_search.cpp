//
// Created by Nishit on 23/01/20.
//

#include <iostream>
#include <vector>
using namespace std;


class LinearSearch{
    vector<int> data;
    int size,key;
public:
    LinearSearch(){
        size=0;
        key=0;
    }
    void getData(){
        cout<<"Enter the size of the array: ";
        cin>>size;
        cout<<"Enter values of the array: ";
        for(int i=0;i<size;i++){
            int temp;
            cin>>temp;
            data.push_back(temp);
        }
        cout<<"Enter key value: ";
        cin>>key;
    }
    void display(){
        for(int i=0;i<data.size();i++){
            cout<<data[i]<<" ";
        }
    }
    void search(){
        bool found=false;
        for (int i = 0; i < data.size(); ++i) {
            if(data[i]==key){
                cout<<"Key found at Index: "<<i<<" Position: "<<i+1;
                found=true;
                break;
            }
        }
        if(!found) {
            data.push_back(key);
            cout<<"Key value not found, added the element at the back"<<endl;
            display();
        }
    }

};
int main(){
    LinearSearch i;
    i.getData();
    i.search();
    return 0;
}

