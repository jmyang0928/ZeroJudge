// AC (2ms, 360KB)
#include<iostream>
#include<vector>
using namespace std;

int N;
vector<vector<long long>> dp(51,vector<long long>(26,-1));
long long func(int cur,int umd){
    if(umd<0) return 0;
    if(dp[50-N*2+cur][umd]!=-1) return dp[50-N*2+cur][umd];
    if(cur==N*2 && umd==0) return dp[50-N*2+cur][umd]=1;
    if(N*2-umd==cur) return dp[50-N*2+cur][umd]=1;
    if(N*2-umd<cur) return dp[50-N*2+cur][umd]=0;
    return dp[50-N*2+cur][umd]=(func(cur+1,umd+1)+func(cur+1,umd-1));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>N){
        cout<<func(0,0)<<endl;
    }
}