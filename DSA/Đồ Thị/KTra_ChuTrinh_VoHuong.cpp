#include <bits/stdc++.h>

using namespace std;

//Kiểm tra chu trình trên đồ thị vô hướng
int n, m;
vector<int> adj[200005];
int vis[200005];
int parent[200005];

void init(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
		
bool dfs(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(vis[v] == 1 && v != parent[u]){
			return true;
		}else if(!vis[v]){
			parent[v] = u;
			if(dfs(v)) return true; //= return dfs(v)
		}
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			if(dfs(i)){
				cout << 1 << '\n';
				return 0;
			}
		}
	}
	cout << 0 << '\n';
	return 0;
}