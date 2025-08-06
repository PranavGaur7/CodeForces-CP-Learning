#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> track;
        for(int i = 0;i<n;i++){
            int k;
            cin>>k;
            int ct = 0;
            int init=0;
            for(int j = 0;j<k;j++){
                int x;
                cin>>x;
                if(j==0){
                    init=x+1;
                    ct=x+1;
                    ct++;
                    continue;
                }
                if(ct<=x){
                    init+=(x+1-ct);
                    ct=x+1;
                }
                ct++;
            }
            track.push_back({init,ct-init});
        }
        sort(track.begin(),track.end());
        int ct = 0;
        int init=0;
        for(int j = 0;j<n;j++){
            int x = track[j].first;
            int d = track[j].second;
            if(j==0){
                init=x;
                ct=x;
                ct+=d;
                continue;
            }
            if(ct<x){
                init+=(x-ct);
                ct=x;
            }
            ct+=d;
        }
        cout<<init<<endl;
    }
    return 0;
}