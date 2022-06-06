// AC (31ms, 1.1MB)
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int n,k,maxN,cur,imposIdx;          //n:儲存木板個數。k:儲存海報個數。maxN:儲存最高木板高度。cur:二分搜目前的index。imposIdx:目前試得最小不可行高度。
vector<int> ni,ki;                  //ni:儲存每根木板高度。ki:儲存每張海報寬度。
bool test(int hight){               //輸入高度，測試是否可行。
    int kIdx=0,conti=0;             //kIdx:準備要張貼的海報。conti:目前可海報的最大寬度。
    for(int nIdx:ni){
        if(nIdx<hight) conti=0;
        else{
            conti++;
            if(conti==ki[kIdx]){
                conti=0;
                if(++kIdx==ki.size()) return true;
            }
        }
    }
    if(kIdx==ki.size()) return true;
    else{
        imposIdx=min(imposIdx,hight);
        return false;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>n>>k){
        maxN=0; imposIdx=INT_MAX; cur=0;
        ni.resize(n); ki.resize(k);
        for(int i=0;i<n;i++){
            cin>>ni[i];
            maxN=max(maxN,ni[i]);
        }
        for(int i=0;i<k;i++) cin>>ki[i];
        for(int jump=maxN/2;jump>0;jump>>=1){
            while(cur+jump<imposIdx && test(cur+jump)) cur+=jump;
        }
        cout<<cur<<endl;
    }

}