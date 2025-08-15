#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    if(n&1){
        cout<<(2*(n/2+1)*(n/2+2))<<endl;
    }
    else cout<<(n/2+1)*(n/2+1)<<endl;
    return 0;
}