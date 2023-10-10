// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int> *l;

public:
    Graph(int v){
        this->v = v;
        this->l = new list<int>[v];
    }

    void addEdge(int x, int y, bool dir = false){
        l[x].push_back(y);
        if(!dir) l[y].push_back(x);
    }
    void bfs(int sv){
        vector<bool> vis(v, false);
        vis[sv] = true;

        queue<int> pv;
        pv.push(sv);

        while(pv.size()){
            int cv = pv.front();
            cout << cv <<" ";
            pv.pop();

            for(int x : l[cv]) if(!vis[x]){
                pv.push(x);
                vis[x] = true;
            }
        }
        cout << endl;
    }
    void print(){
        for(int i=0 ; i<v ; i++){
            cout << i <<" -> ";
            for(int x : l[i])
                cout << x <<" ";
            cout << endl;
        }
    }
};

signed main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 2);
    g.addEdge(3, 4);

    g.print();
    g.bfs(0);
    
}
