//AC (18ms, 348KB)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

string startNode,endNode;                                   //startNode:起始座標(輸入資料)。endNode:終點座標(輸入資料)。
vector<int> startIdx(2),endIdx(2),curIdx(2),nextIdx(2);     //startIdx:起始座標。endIdx:終點座標。curIdx:目前座標。nextIdx:BFS走訪時curIdx下一步的座標。
queue<vector<int>> qu;                                      //qu:儲存BFS走訪資料。
int mv[10]={1,2,2,1,-1,-2,-2,-1,1,2};                       //以變數i執行0~7，X軸位置+mv[i]，Y軸位置+mv[i+2]，走訪8個能到達的位置。
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>startNode>>endNode){
        startIdx[0]=startNode[0]-'a'; startIdx[1]=startNode[1]-'1';
        endIdx[0]=endNode[0]-'a'; endIdx[1]=endNode[1]-'1';
        vector<vector<int>> bfs(8,vector<int>(8,-1));
        bfs[startIdx[0]][startIdx[1]]=0;
        if(startIdx[0]!=endIdx[0] || startIdx[1]!=endIdx[1]){   //若起點等於終點，距離等於0，不須BFS走訪。
            while(!qu.empty()) qu.pop();
            qu.push(startIdx);
            while(true){
                curIdx=qu.front();
                qu.pop();
                for(int i=0;i<8;i++){
                    nextIdx[0]=curIdx[0]+mv[i]; nextIdx[1]=curIdx[1]+mv[i+2];
                    if(nextIdx[0]==endIdx[0] && nextIdx[1]==endIdx[1]){
                        bfs[nextIdx[0]][nextIdx[1]]=bfs[curIdx[0]][curIdx[1]]+1;
                        break;
                    }
                    else if(nextIdx[0]>=0 && nextIdx[0]<8 && nextIdx[1]>=0 && nextIdx[1]<8 && bfs[nextIdx[0]][nextIdx[1]]==-1){
                        bfs[nextIdx[0]][nextIdx[1]]=bfs[curIdx[0]][curIdx[1]]+1;
                        qu.push(nextIdx);
                    }
                }
                if(nextIdx[0]==endIdx[0] && nextIdx[1]==endIdx[1]) break;
            }
        }
        cout<<"To get from "<<startNode<<" to "<<endNode<<" takes "<<bfs[endIdx[0]][endIdx[1]]<<" knight moves.\n";
    }
}