// ~BhupinderJ
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int nmx = 1e6 + 1;

void dfs(int cv, int pv, vector<int> *edge)
{
    cout << cv << "\n";
    for (auto v : edge[cv])
    {
        if (v == pv)
            continue;
        dfs(v, cv, edge);
    }
}
signed main()
{
    int n;
    cin >> n;
    vector<int> edge[n];

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(0, -1, edge);
}
