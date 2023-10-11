// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

int n, m;

class Node
{
public:
    char c;
    bool isTerminal;
    string word;
    Node **children;

    Node(char c)
    {
        this->c = c;
        this->children = new Node *[26];
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = nullptr;
        }
        this->isTerminal = false;
        this->word = "";
    }
    ~Node()
    {
        delete[] children;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }
    void addWord(string word)
    {
        Node *temp = root;
        for (char c : word)
        {
            if (temp->children[c - 'a'] == nullptr)
            {
                temp->children[c - 'a'] = new Node(c);
            }
            temp = temp->children[c - 'a'];
        }
        temp->isTerminal = true;
        temp->word = word;
    }
};
bool isVal(int i, int j)
{
    return (i < n and j < m and i >= 0 and j >= 0);
}
void dfs(vector<string> &board, Node *node, int i, int j, vector<vector<int>> &vis, unordered_set<string> &output)
{
    char c = board[i][j];

    if (node->children[c - 'a'] == nullptr)
        return;

    vis[i][j] = true;
    node = node->children[c - 'a'];

    if (node->isTerminal)
        output.insert(node->word);

    int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int x = 0; x < 8; x++)
    {
        int ii = i + di[x];
        int jj = j + dj[x];

        if (isVal(ii, jj) and (!vis[ii][jj]))
            dfs(board, node, ii, jj, vis, output);
    }
    vis[i][j] = false;
}
signed main()
{
    n = 3, m = 4;
    vector<string> board = {"sert", "unks", "tcat"};
    vector<string> words = {"snake", "for", "quez", "snack", "snacks", "sens", "tunes", "cat"};

    Trie tt;
    for (auto w : words)
    {
        tt.addWord(w);
    }

    unordered_set<string> output;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dfs(board, tt.root, i, j, vis, output);
        }
    }

    for (auto w : output)
        cout << w << " ";
    cout << endl;
}

/* ---------------------------------------------------------------------------------------------- */

/* TRADITION WAY I USED TO DO*/

// assume k words
// time complexity = O(k*n*m)

// ~BhupinderJ
// #include <bits/stdc++.h>
// using namespace std;

// int n, m;

// int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// bool isVal(int i, int j)
// {
//     return (i < n and j < m and i >= 0 and j >= 0);
// }
// bool dfs(vector<string> &v, vector<vector<int>> &vis, int i, int j, string s, int si)
// {
//     if (si == s.size())
//         return true;

//     vis[i][j] = 1;

//     for (int x = 0; x < 8; x++)
//     {
//         int ii = i + di[x];
//         int jj = j + dj[x];

//         if (isVal(ii, jj) and (!vis[ii][jj]) and (v[ii][jj] == s[si]) and dfs(v, vis, ii, jj, s, si + 1))
//             return true;
//     }
//     return false;
// }
// bool check(vector<string> &v, string s)
// {
//     vector<vector<int>> vis(n, vector<int>(m, 0));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//             if (v[i][j] == s[0] and (!vis[i][j]) and dfs(v, vis, i, j, s, 1))
//                 return true;
//     }
//     return false;
// }
// signed main()
// {
//     cin >> n >> m;
//     vector<string> v(n);

//     for (int i = 0; i < n; i++)
//         cin >> v[i];

//     vector<string> words = {"snake", "for", "quez", "snack", "snacks", "sens", "tunes", "cat"};

//     for (string s : words)
//     {
//         if (check(v, s))
//             cout << "yes ";
//         else
//             cout << "no ";
//     }
// }
