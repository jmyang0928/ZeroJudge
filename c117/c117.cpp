//AC (18ms, 348KB)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

string startNode,endNode;
vector<int> startIdx(2),endIdx(2),curIdx(2),nextIdx(2);
queue<vector<int>> qu;
int mv[10]={1,2,2,1,-1,-2,-2,-1,1,2};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>startNode>>endNode){
        startIdx[0]=startNode[0]-'a'; startIdx[1]=startNode[1]-'1';
        endIdx[0]=endNode[0]-'a'; endIdx[1]=endNode[1]-'1';
        vector<vector<int>> bfs(8,vector<int>(8,-1));
        bfs[startIdx[0]][startIdx[1]]=0;
        if(startIdx[0]!=endIdx[0] || startIdx[1]!=endIdx[1]){
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