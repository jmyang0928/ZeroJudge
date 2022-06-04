//AC (2ms, 336KB)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
string input;
int maxUsage;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N;
    cin.ignore();
    while(N--){
        maxUsage=0;
        vector<int> usage(26,0);
        getline(cin,input);
        sort(input.begin(),input.end());
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