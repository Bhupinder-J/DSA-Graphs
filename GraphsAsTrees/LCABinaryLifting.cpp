// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>

void dfs(int cv, int pv, vi* edge, vi &dep, vvi &par){
	dep[cv] = 1 + dep[pv];

	par[cv][0] = pv;
	for(int i=1 ; i<20 ; i++){
		par[cv][i] = par[par[cv][i-1]][i-1];
	}
	for(int v : edge[cv]){
		if(v == pv) continue;
		dfs(v, cv, edge, dep, par);
	}
}
int LCA(int x, int y, vi &dep, vvi &par){
	if(dep[x] < dep[y])
		swap(x, y);
	
	int d = dep[x] - dep[y];
	for(int i=19;  i>=0 ; i--){
		if((1<<i) <= d){
			d -= (1<<i);
			x = par[x][i];
		}
	}

	for(int i=19 ; i>=0 ; i--){
		if(par[x][i] != par[y][i]){
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}
signed main(){
	int n; cin >> n;
	vi edge[n+1];
	for(int i=1 ; i<n ; i++){
		int x, y; cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	vi dep(n+1, 0);
	vvi par(n+1, vi(20, 0));

	dfs(1, 0, edge, dep, par);

	// for(int i=0 ; i<n ; i++){
	// 	cout << i+1 <<" -> ";
	// 	for(int j=0 ; j<4 ; j++)
	// 		cout << par[i+1][j] <<" ";
	// 	cout << endl;
	// }

	cout << LCA(9, 12, dep, par) << endl;
	cout << LCA(10, 8, dep, par) << endl;
	cout << LCA(9, 11, dep, par) << endl;
}