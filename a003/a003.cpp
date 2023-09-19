// AC (3ms, 364KB)
// Author: JMYANG

#include<iostream>
using namespace std;
int main(){
    int M,D;
    while(cin>>M>>D){
        if((M*2+D)%3==0){
            cout<<"普通"<<endl;
        }
        else if((M*2+D)%3==1){
            cout<<"吉"<<endl;
        }
        else{
            cout<<"大吉"<<endl;
        }
    }
}