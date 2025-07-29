#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> mp(200005, 0);
        vector<vector<int>> c;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            vector<int> v(k);
            for(int j = 0; j < k; j++){
                cin >> v[j];
                mp[v[j]]++;
            }
            c.push_back(v);
        }

        bool res = 0;
        for(auto it : c){
            bool pos = 1;
            for(auto j:it){
                if(mp[j]==1) {
                    pos=0;
                    break;
                }
            }
            if(pos){
                res=1;
                break;
            }
        }

        cout << (res ? "YES" : "NO") << endl;
    }
    return 0;
}
