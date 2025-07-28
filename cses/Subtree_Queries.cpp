#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int node_ind[200005];
int subTreeSize[200005];

vector<ll> nums;

ll dfs(ll node, vector<ll> &vis, vector<vector<ll>> &mp, vector<ll> &v)
{
    nums.push_back(v[node]);
    vis[node] = 1;
    ll res = 1;
    node_ind[node] = nums.size() - 1;
    for (auto it : mp[node])
    {
        if (!vis[it])
        {
            res += dfs(it, vis, mp, v);
        }
    }
    subTreeSize[node] = res;
    return res;
}

void buildTree(ll ind, ll l, ll r, vector<ll> &segTree)
{
    if (l == r)
    {
        segTree[ind] = nums[l];
        return;
    }
    ll mid = (l + r) / 2;
    buildTree(ind * 2 + 1, l, mid, segTree);
    buildTree(ind * 2 + 2, mid + 1, r, segTree);
    segTree[ind] = segTree[ind * 2 + 1] + segTree[ind * 2 + 2];
}

void updateTree(ll ind, ll l, ll r, ll index, ll val, vector<ll> &segTree)
{
    if (l == r)
    {
        segTree[ind] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (index <= mid)
        updateTree(ind * 2 + 1, l, mid, index, val, segTree);
    else
        updateTree(ind * 2 + 2, mid + 1, r, index, val, segTree);
    segTree[ind] = segTree[ind * 2 + 1] + segTree[ind * 2 + 2];
}

ll query(ll ind, ll l, ll r, ll st, ll ed, vector<ll> &segTree)
{
    if (l >= st && r <= ed)
        return segTree[ind];

    if (r < st || l > ed)
        return 0;
    ll mid = (l + r) / 2;
    return query(ind * 2 + 1, l, mid, st, ed, segTree) + query(ind * 2 + 2, mid + 1, r, st, ed, segTree);
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<ll>> mp(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        mp[x - 1].push_back(y - 1);
        mp[y - 1].push_back(x - 1);
    }
    vector<vector<ll>> queries;
    for (ll i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll s, a;
            cin >> s >> a;
            queries.push_back({x, s - 1, a});
        }
        else
        {
            ll s;
            cin >> s;
            queries.push_back({x, s - 1});
        }
    }
    vector<ll> vis(n, 0);
    dfs(0, vis, mp, v);

    vector<ll> segTree(4 * n, 0);

    buildTree(0, 0, n - 1, segTree);

    vector<ll> res;

    for (auto it : queries)
    {
        if (it[0] == 1)
        {
            updateTree(0, 0, n - 1, node_ind[it[1]], it[2], segTree);
        }
        else
        {
            res.push_back(query(0, 0, n - 1, node_ind[it[1]], node_ind[it[1]] + subTreeSize[it[1]] - 1, segTree));
        }
    }

    for (auto it : res)
        cout << it << endl;

    return 0;
}
