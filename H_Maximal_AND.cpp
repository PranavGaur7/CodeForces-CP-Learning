#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> bc(33,0);
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            ll x = a[i];
            for (ll j = 32; j >= 0; j--)
            {
                if (x & (1 << j))
                    bc[j]++;
            }
        }
        
        // for (ll j = 32; j >= 0; j--) cout<<bc[j]<<" ";
        // cout<<endl;
        ll res = 0;
        for (ll j = 30; j >= 0; j--)
        {
            if(n-bc[j]<=k){
                // cout<<j<<" ";
                res+=(1<<j);
                k-=(n-bc[j]);
            }
        }
        res+=((1<<31)*bc[31]);
        res+=((1<<32)*bc[32]);
        // cout<<"res: "<<res<<endl;
        cout<<res<<endl;
    }
    return 0;
}