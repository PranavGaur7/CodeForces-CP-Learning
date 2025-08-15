#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 0;i<n-1;i++) {
        int x;
        cin>>x;
        sum+=i+1-x;
    }
    cout<<sum+n<<endl;
    return 0;
}