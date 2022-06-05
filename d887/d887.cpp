// AC (2ms, 360KB)
#include<iostream>
#include<vector>
using namespace std;

int N;
vector<vector<long long>> dp(51,vector<long long>(26,-1));      //:dp儲存動態規劃資料。一維:50-剩餘待安排山脈的格子數。二維:以使用向上山脈-向下山脈數量(亦表示剩餘待安排山脈向下山脈需大於向上山脈個數)。
long long func(int cur,int umd){
    if(umd<0) return 0;                                                 //若向下山脈數>向上山脈數，則此山脈不成立。
    if(dp[50-N*2+cur][umd]!=-1) return dp[50-N*2+cur][umd];             //若dp陣列內有資料，則不需重複計算。
    if(cur==N*2 && umd==0) return dp[50-N*2+cur][umd]=1;                //若此山脈全部都已安排完畢，則回傳1。
    if(N*2-umd==cur) return dp[50-N*2+cur][umd]=1;                      //若此山脈剩餘待安排數量等於還需要向下山脈的數量，則回傳1(表示往後全部都為向下)。
    if(N*2-umd<cur) return dp[50-N*2+cur][umd]=0;                       //若此山脈剩餘待安排數輛小於還需要向下山脈的數量，則回傳0。
    return dp[50-N*2+cur][umd]=(func(cur+1,umd+1)+func(cur+1,umd-1));   //否則回傳此格子安排向上和向下的方法數總和。
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>N){
        cout<<func(0,0)<<endl;
    }
}