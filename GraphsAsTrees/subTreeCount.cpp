// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

void dfs(int cv, int pv, vector<int> *edge, vector<int> &count)
{
    count[cv] = 1;

    for (int v : edge[cv])
    {
        if (v == pv)
            continue;
        dfs(v, cv, edge, count);
        count[cv] += count[v];
    }
}
vector<int> subtreeProblem(int n, vector<vector<int>> edges, vector<int> queries)
{
    vector<int> edge[n + 1];
    for (auto e : edges)
    {
        edge[e[0]].push_back(e[1]);
        edge[e[1]].push_back(e[0]);
    }
    vector<int> count(n + 1, 0);
    dfs(1, -1, edge, count);

    for (int &x : queries)
    {
        x = count[x];
    }
    return queries;
}
signed main()
{
    int n = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    vector<int> queries = {1, 2, 3, 4, 5};

    vector<int> ans = subtreeProblem(n, edges, queries);

    for (int x : ans)
        cout << x << " ";
    cout << endl;
}
