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
        multiset<int> st;
        ll res = 0;
        for(int i = 0;i<n;i++) {
            int x;
            cin>>x;
            if(x<(i+1)){
                if(!st.empty()){
                    auto it = st.lower_bound(x);
                    res+=distance(st.begin(),it);
                }
                st.insert(i+1);
            }
        }

        cout<<res<<endl;
    }
    
    return 0;
}