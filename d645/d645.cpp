// NA (score:30%)
// #1: 35% TLE (1s)
// Killed
#include<iostream>
#include<vector>
using namespace std;

int I,C;
vector<vector<int>> dp,feed;
int dpFunc(int f,int w){
    int t,cur;
    if(f<0 || w<0) return 0;
    if(dp[f][w]!=-1) return dp[f][w];
    if(feed[f][2]==-1){
        cur=w-feed[f][1];
        t=1;
        while(cur>=0){
            dp[f][w]=max(dp[f][w],dpFunc(f-1,cur)+feed[f][0]*t);
            cur-=feed[f][1];
            t++;
        }
    }
    else{
        cur=w-feed[f][1];
        for(t=1;t<=feed[f][2];t++){
            if(cur<0) break;
            dp[f][w]=max(dp[f][w],dpFunc(f-1,cur)+feed[f][0]*t);
            cur-=feed[f][1];
        }
    }
    // for(cur=1;cur<feed[f][1];cur++){
    //     dp[f][w]=max(dp[f][w],dpFunc(f,w-cur));
    // }
    if(f!=0) dp[f][w]=max(dp[f][w],dpFunc(f-1,w));
    return dp[f][w];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    while(cin>>I>>C){
        dp.resize(0); dp.resize(I,vector<int>(C+1,-1));
        feed.resize(I,vector<int>(3));
        for(int i=0;i<I;i++) for(int j=0;j<3;j++) cin>>feed[i][j];
        cout<<dpFunc(I-1,C)<<endl;
    }
}