#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        vector<int> bitct(31,0);
        int n;
        cin>>n;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            for(int i=0;i<=30;i++) if(x&(1<<i)) bitct[i]++;
        }
        int g;
        bool fd = 0;
        for(int i=0;i<=30;i++){
            if(bitct[i]>0){
                if(!fd){
                    fd=1;
                    g=bitct[i];
                }
                else g = __gcd(g,bitct[i]); 
            }
        }
        if(!fd){
            for(int i = 1;i<=n;i++) cout<<i<<" ";
            cout<<endl;
            continue;
        }
        vector<int> res;
        for(int i = 1;i*i<=g;i++){
            if(g%i==0){
                res.push_back(i);
                if(i!=g/i) res.push_back(g/i);
            }
        }
        sort(res.begin(),res.end());
        for(auto it:res) cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}