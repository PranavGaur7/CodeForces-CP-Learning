#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,W;
        cin>>n>>W;
        vector<int> w(20,0);
        for(int i = 0;i<n;i++) {
            int a;
            cin>>a;
            w[log2(a)]++;
        }
        int res = 0;
        while(n>0){
            int x = W;
            for(int i = 19;i>=0;i--){
                if(w[i]>0 && x>=(1<<i)){
                    // cout<<"YES"<<endl;
                    int div = min(x/(1<<i),w[i]);
                    n-=div;
                    x-=(1<<i)*div;
                    w[i]-=div;
                }
            }
            res++;
        }
        cout<<res<<endl;
        // ajsnd
    }
    return 0;
}