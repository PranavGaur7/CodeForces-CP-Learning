#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> k(n);
        vector<int> c(m);
        for(int i = 0;i<n;i++) cin>>k[i];
        for(int i = 0;i<m;i++) cin>>c[i];
        sort(k.begin(),k.end(),greater<int>());
        int i=0,j=0;
        long long res=0;
        while(i<n && j<m){
            if(c[j]<c[k[i]-1]){
                res+=c[j];
                j++;
            }
            else res+=c[k[i]-1];
            i++;
        }
        while(i<n){
            res+=c[k[i]-1];
            i++;
        }
        cout<<res<<endl;
    }
    return 0;
}