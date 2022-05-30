//AC (52ms, 1.5MB)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int X,Y,idx;            //X:小智的牌數。Y:小遙的牌數。idx:二分搜index。
long long winX;         //winX:小智贏的組合-小瑤贏的組合。
vector<int> vecX,vecY;  //vecX:儲存小智的手牌。vecY:儲存小遙的手牌。
vector<int> vecWin;     //vecWin:儲存小智每張手牌贏的組數-書的組數。
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>X>>Y){
        vecX.clear(); vecY.clear(); vecWin.clear();
        vecX.resize(X); vecY.resize(Y); vecWin.resize(X);
        for(int i=0;i<X;i++) cin>>vecX[i];
        for(int i=0;i<Y;i++) cin>>vecY[i];
        sort(vecX.begin(),vecX.end());
        sort(vecY.begin(),vecY.end());
        winX=0;
        //計算小智每張手牌贏的組數-輸的組數
        for(int i=0;i<X;i++) winX += vecWin[i] = (lower_bound(vecY.begin(),vecY.end(),vecX[i])-vecY.begin()) - (Y - (upper_bound(vecY.begin(),vecY.end(),vecX[i])-vecY.begin()));
        if(winX<0 && Y<-winX) cout<<-1<<endl;   //若小智(輸的組數-贏的組數)比小遙的牌數還多，則不可能完成任務，輸出-1。
        else{
            //依照題意，若小智原本贏的組數>輸的組數，則尋找贏的組數>=輸的組數最小的牌；反之，則試圖尋找符合(總贏的組數>總輸的組數)的牌。
            idx=(winX>0) ? (lower_bound(vecWin.begin(),vecWin.end(),0) - vecWin.begin()) : (upper_bound(vecWin.begin(),vecWin.end(),-winX) - vecWin.begin());
            cout<<((idx==X) ? -1 : vecX[idx])<<endl;
        }
    }
}