//AC (11ms, 320KB)
#include<iostream>
#include<vector>
using namespace std;

vector<int> box(7);         //從box[1]到box[6]，分別儲存1*1到6*6的箱子數。
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>box[1]){
        for(int i=2;i<=6;i++) cin>>box[i];
        if(box[1]==0 && box[2]==0 && box[3]==0 && box[4]==0 && box[5]==0 && box[6]==0) break;       //終止條件
        while(box[5]>0){
            //1個box[5]、11個box[1]可以合成1個box[6]。
            box[1]=(box[1]<=11) ? 0 : box[1]-11;
            box[5]--;
            box[6]++;
        }
        while(box[4]>0){
            //1個box[4]、5個box[2]可以合成1個box[6]。
            box[1]=(box[2]<5) ? ((box[1]>(5-box[2])*4) ? (box[1]-(5-box[2])*4) : 0) : box[1];
            box[2]=(box[2]>5) ? box[2]-5 : 0;
            box[4]--;
            box[6]++;
        }
        while(box[3]>0){
            //4個box[3]可以合成1個box[6]。
            //3個box[3]、1個box[2]、5個box[1]可以合成1個box[6]
            //2個box[3]、3個box[2]、6個box[1]可以合成1個box[6]
            //1個box[3]、5個box[2]、7個box[1]可以合成1個box[6]
            box[1]=(box[3]<4) ? (((4-box[3])*2-1>box[2]) ? ((box[1]>36-box[2]*4-box[3]*9) ? box[1]-(36-box[2]*4-box[3]*9) : 0) : (((7>box[1]) ? 0 : box[1]-7))) : box[1];
            box[2]=(box[3]<4) ? box[2]-(4-box[3])*2+1 : box[2];
            box[3]=(box[3]<4) ? 0 : box[3]-4;
            box[6]++;
        }
        while(box[2]>0){
            //9個box[2]可以合成1個box[6]
            box[1]=(box[2]<9) ? ((box[1]<(9-box[2])*4) ? 0 : box[1]-(9-box[2])*4) : box[1];
            box[2]=(box[2]<9) ? 0 : box[2]-9;
            box[6]++;
        }
        while(box[1]>0){
            //36個box[1]可以合成1個box[6]
            box[1]=(box[1]<36) ? 0 : box[1]-36;
            box[6]++;
        }
        cout<<box[6]<<endl;
    }
}


