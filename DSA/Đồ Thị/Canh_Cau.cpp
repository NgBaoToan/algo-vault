#include <bits/stdc++.h>
using namespace std;
int n, m, s, t; 
vector<int> adj[200005];
int vis[200005];
int parent[200005];
vector<pair<int, int>> dsc;

void init(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		dsc.push_back({x, y});
	}
}

void dfs(int u, int s, int t){
	vis[u] = 1;
	for(int v : adj[u]){
		if((u == s && v == t) || (u == t && v == s)) continue;
		if(!vis[v]){
			dfs(v, s, t);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	int cnt1 = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cnt1++;
			dfs(i, 0, 0);
		}
	}
	
	int cau = 0;
	
	for(pair<int, int> e : dsc){
		int x = e.first; 
		int y = e.second;
		memset(vis, 0, sizeof(vis));
		int cnt2 = 0;
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				cnt2++;
				dfs(i, x, y);
			}
		}
		if(cnt2 > cnt1) cau++;
	}
	cout << cau;
	return 0;
}