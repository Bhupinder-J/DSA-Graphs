// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int nmx = 1e6 + 1;
int n, m;

int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isVal(int i, int j)
{
    return (i < n and j < m and i >= 0 and j >= 0);
}
bool dfs(vector<string> &v, vector<vector<int>> &vis, int i, int j, string s, int si)
{
    if (si == s.size())
        return true;

    vis[i][j] = 1;

    for (int x = 0; x < 8; x++)
    {
        int ii = i + di[x];
        int jj = j + dj[x];

        if (isVal(ii, jj) and (!vis[ii][jj]) and (v[ii][jj] == s[si]) and dfs(v, vis, ii, jj, s, si + 1))
            return true;
    }
    return false;
}
bool check(vector<string> &v, string s)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (v[i][j] == s[0] and (!vis[i][j]) and dfs(v, vis, i, j, s, 1))
                return true;
    }
    return false;
}
signed main()
{
    cin >> n >> m;
    vector<string> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<string> words = {"snake", "for", "quez", "snack", "snacks", "sens", "tunes", "cat"};

    for (string s : words)
    {
        if (check(v, s))
            cout << "yes ";
        else
            cout << "no ";
    }
}
