#include<bits/stdc++.h>
using namespace std;

pair<int,int> dfs(int node,vector<vector<int>>& mp,string s,int& res){
    int b=0,w=0;
    (s[node-1]=='B'?b++:w++);
    for(auto it:mp[node]){
        auto [bl,wt] = dfs(it,mp,s,res);
        b+=bl;
        w+=wt;
    }
    if(b==w) res++;
    return {b,w};
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> mp(4001);
        for(int i = 2;i<=n;i++){
            int x;
            cin>>x;
            mp[x].push_back(i);
        }
        string s;
        cin>>s;
        int res = 0;
        dfs(1,mp,s,res);
        cout<<res<<endl;
    }
    return 0;
}