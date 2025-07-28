#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> ancestor(200005, vector<ll>(21, -1));
vector<vector<ll>> mp(200005);

void preprocess(ll node, ll par)
{
    ancestor[node][0] = par;

    for (int i = 1; i <= 20; i++)
    {
        if (ancestor[node][i - 1] != -1)
            ancestor[node][i] = ancestor[ancestor[node][i - 1]][i - 1];
        else
            ancestor[node][i] = -1;
    }

    for (auto it : mp[node])
    {
        preprocess(it, node);
    }
}

ll query(ll node, ll k)
{
    if (k == 0)
    {
        return node;
    }
    if (node == -1)
    {
        return -1;
    }

    for (int i = 20; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            return query(ancestor[node][i], k - (1 << i));
        }
    }
    return -1;
}

int main()
{
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n - 1; i++)
    {
        ll x;
        cin >> x;
        mp[x - 1].push_back(i + 1);
    }
    vector<vector<ll>> queries;
    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        queries.push_back({x - 1, y});
    }

    preprocess(0, -1);

    for (auto it : queries)
    {
        int x = query(it[0], it[1]);
        cout << (x != -1 ? x + 1 : -1) << endl;
    }

    return 0;
}
