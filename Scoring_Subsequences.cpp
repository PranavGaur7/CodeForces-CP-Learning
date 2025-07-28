#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0;i<n;i++) cin>>a[i];
        for(int i = 0;i<n;i++){
            int l = 0,h=i;
            while(l<=h){
                int m = (l+h)/2;
                if(a[m]>=(i-m+1)) h=m-1;
                else l = m+1;
            }
            cout<<(i-l+1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}