#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> ancestor(200005, vector<ll>(21, -1));
vector<vector<ll>> mp(200005);
vector<ll> depth(200005);

void preprocess(ll node, ll par, ll d)
{
    ancestor[node][0] = par;
    depth[node] = d;

    for (int i = 1; i <= 20; i++)
    {
        if (ancestor[node][i - 1] != -1)
            ancestor[node][i] = ancestor[ancestor[node][i - 1]][i - 1];
        else
            ancestor[node][i] = -1;
    }

    for (auto it : mp[node])
    {
        if (it == par)
            continue;
        preprocess(it, node, d + 1);
    }
}

ll query(ll a, ll b)
{
    if (depth[a] > depth[b])
        return query(b, a);
    ll d = depth[b] - depth[a];
    for (int i = 20; i >= 0; i--)
    {
        if (d & (1 << i))
            b = ancestor[b][i];
    }
    if (a == b)
        return a;

    for (ll i = 20; i >= 0; i--)
    {
        if (ancestor[a][i] != ancestor[b][i])
        {
            a = ancestor[a][i];
            b = ancestor[b][i];
        }
    }
    return ancestor[a][0];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        mp[x - 1].push_back(y - 1);
        mp[y - 1].push_back(x - 1);
    }
    preprocess(0, -1, 0);
    for (ll i = 0; i < q; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--; 
        v--;

        int lca = query(u, v);
        int d1 = depth[u] - depth[lca];
        int d2 = depth[v] - depth[lca];
        cout << d1 + d2 << "\n"; 
    }

    return 0;
}