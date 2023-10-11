// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        this->l = new list<int>[v];
    }

    void addEdge(int x, int y, bool dir = false)
    {
        l[x].push_back(y);
        if (!dir)
            l[y].push_back(x);
    }
    void bfs(int sv, int dv = -1)
    {
        vector<bool> vis(v, false);
        vector<int> dis(v, 0);
        vector<int> parent(v, -1);
        queue<int> pv;

        vis[sv] = true;
        parent[sv] = sv;
        pv.push(sv);

        while (pv.size())
        {
            int cv = pv.front();
            pv.pop();

            for (int x : l[cv])
                if (!vis[x])
                {
                    pv.push(x);
                    vis[x] = true;
                    parent[x] = cv;
                    dis[x] = dis[cv] + 1;
                }
        }

        if (dv != -1)
        {
            vector<int> path(1, dv);
            while (parent[dv] != dv)
            {
                dv = parent[dv];
                path.push_back(dv);
            }
            reverse(path.begin(), path.end());
            for (int x : path)
                cout << x << " ";
            cout << endl;
        }
    }
    void dfs(int sv)
    {
        vector<bool> vis(v, false);
        dfs_helper(sv, vis);
    }
    void dfs_helper(int sv, vector<bool> &vis)
    {
        vis[sv] = true;
        for (int x : l[sv])
            if (!vis[x])
            {
                dfs_helper(x, vis);
            }
    }
    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " -> ";
            for (int x : l[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

signed main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    g.print();
    g.bfs(3, 6);
}
