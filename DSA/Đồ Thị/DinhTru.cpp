#include <bits/stdc++.h>
using namespace std;
int n, m, s, t; 
vector<int> adj[200005];
int vis[200005];
int parent[200005];

void init(){
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cnt++;
			dfs(i);
		}
	}
	
	int tru = 0;
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis)){
			vis[i] = 1;
			int cnt2 = 0;
			for(int i = 1; i <= n; i++){
				if(!vis[i]){
					cnt2++;
					dfs(i);
				}
			}
			if(cnt2 > cnt) tru++;
		}
	}
	cout << tru;
	return 0;
}