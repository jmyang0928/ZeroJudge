//AC (2ms, 336KB)
// Author: JMYANG
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;          //N:紀錄測資筆數。
string input;   //input:儲存當筆測資。
int maxUsage;   //maxUsage:紀錄最大使用量的數值。
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N;
    cin.ignore();               //cin後使用getline前要加上cin.ignore()。
    while(N--){
        maxUsage=0;
        vector<int> usage(26,0);
        getline(cin,input);     //讀入一行測資。
        for(char c:input){
            if(c>='a' && c<='z'){
                usage[c-'a']++;
                maxUsage=max(maxUsage,usage[c-'a']);
            }
            else if(c>='A' && c<='Z'){
                usage[c-'A']++;
                maxUsage=max(maxUsage,usage[c-'A']);
            }
        }
        for(int i=0;i<26;i++){
            if(usage[i]==maxUsage) cout<<char('a'+i);
        }
        cout<<endl;
    }
}