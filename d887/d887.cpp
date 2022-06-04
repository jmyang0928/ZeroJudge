#include<iostream>
using namespace std;

int N;
long long func(int cur,int umd){
    if(cur==N*2 && umd==0) return 1;
    if(umd<0) return 0;
    if(N*2-umd==cur) return 1;
    return func(cur+1,umd+1)+func(cur+1,umd-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>N){
        cout<<func(0,0)<<endl;
    }
}