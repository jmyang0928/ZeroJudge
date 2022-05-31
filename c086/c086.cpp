//AC (3ms, 324KB)
#include<iostream>
#include<vector>
using namespace std;

int N,X,selection=0,curCard,curIdx;
vector<short> people;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>N>>X){
        selection++;
        people.resize(N);
        for(int i=0;i<N;i++) people[i]=i;
        for(int i=0;i<20;i++){
            cin>>curCard;
            if(people.size()==X) continue;
            curIdx=--curCard;
            while(people.size()>X && curIdx<people.size()){
                people.erase(people.begin()+curIdx);
                curIdx+=curCard;
            }
        }
        cout<<"Selection #"<<selection<<endl;
        for(int p:people) cout<<p+1<<" ";
        cout<<endl<<endl;
    }
}