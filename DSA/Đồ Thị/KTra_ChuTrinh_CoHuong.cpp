#include <bits/stdc++.h>

using namespace std;

/*
Kiểm tra chu trình trên đồ thị có hướng
Quy ước mảng color:
	0: chưa xét
	1: đang xét
	2: đã xét xong
*/
int n, m;
vector<int> adj[200005];
int color[200005];
int parent[200005];

void init(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
}
		
bool dfs(int u){
	color[u] = 1;
	for(int v : adj[u]){
		if(color[v] == 1){
			return true;
		}else if(color[v] == 0){
			parent[v] = u;
			if(dfs(v)) return true;
		}
	}
	color[u] = 2;
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	for(int i = 1; i <= n; i++){
		if(!color[i]){
			if(dfs(i)){
				cout << 1 << '\n';
				return 0;
			}
		}
	}
	cout << 0 << '\n';
	return 0;
}