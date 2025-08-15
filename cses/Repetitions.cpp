#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int prev = 'Z';
    int ct = 1;
    int res = 0;
    for(auto it:s){
        if(it!=prev){
            res = max(res,ct);
            ct=1;
            prev=it;
        }
        else ct++;
    }
    res=max(res,ct);
    cout<<res<<endl;
    return 0;
}