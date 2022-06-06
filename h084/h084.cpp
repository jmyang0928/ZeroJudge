// AC (31ms, 1.1MB)
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int n,k,maxN;
int cur;
vector<int> ni,ki;
bool test(int hight){
    int kIdx=0,conti=0;
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
    else return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>n>>k){
        ni.resize(n); ki.resize(k); maxN=0;
        for(int i=0;i<n;i++){
            cin>>ni[i];
            maxN=max(maxN,ni[i]);
        }
        for(int i=0;i<k;i++) cin>>ki[i];
        cur=0;
        for(int jump=maxN/2;jump>0;jump>>=1){
            while(test(cur+jump)) cur+=jump;
        }
        cout<<cur<<endl;
    }

}