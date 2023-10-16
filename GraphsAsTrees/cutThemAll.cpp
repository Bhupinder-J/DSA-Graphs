// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

void dfs(int cv, int pv, vi *edge, vi &count, int &ans)
{
    for (int v : edge[cv])
    {
        if (v == pv)
            continue;
        dfs(v, cv, edge, count, ans);
        count[cv] += 1 + count[v];

        if (count[v] & 1)
        {
            ans += 1;
        }
    }
}
int solve(int n, vector<vector<int>> edges)
{
    if (n & 1)
        return -1;

    vi edge[n + 1];
    for (auto e : edges)
    {
        edge[e[0]].push_back(e[1]);
        edge[e[1]].push_back(e[0]);
    }
    vi count(n + 1, 0);
    int ans = 0;
    dfs(1, -1, edge, count, ans);
    return ans ? ans : -1;
}
signed main()
{
    int n = 4;
    vector<vi> edges = {{2, 4}, {1, 4}, {1, 3}};

    cout << solve(n, edges) << endl;
}
