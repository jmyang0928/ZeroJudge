// AC (7ms, 312KB)
// Author: JMYANG

#include<iostream>
using namespace std;

int main(){
    int year;
    while(cin>>year){
        if(year % 400 == 0){
            cout<<"閏年"<<endl;
        }
        else if(year % 100 == 0){
            cout<<"平年"<<endl;
        }
        else if(year % 4 == 0){
            cout<<"閏年"<<endl;
        }
        else{
            cout<<"平年"<<endl;
        }
    }
}