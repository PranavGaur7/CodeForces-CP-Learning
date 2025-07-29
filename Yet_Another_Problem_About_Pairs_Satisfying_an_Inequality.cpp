#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v;
        ll res = 0;
        for(int i = 0;i<n;i++) {
            int x;
            cin>>x;
            if(x<(i+1)){
                if(!v.empty()){
                    auto it = lower_bound(v.begin(),v.end(),x);
                    res+=it-v.begin();
                }
                v.push_back(i+1);
            }
        }

        cout<<res<<endl;
    }
    
    return 0;
}