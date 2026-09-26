#include <bits/stdc++.h>
using namespace std;
//tạo thứ tự topo để check xem có chu trình không
//có hướng và không có chu trình thì tồn tại thứ tự topo
//thuật toán dựa trên dfs
int n, m;
vector<int> adj[20005];
int vis[20005];
stack<int> st;
void init(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
}
void dfs(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
	st.push(u);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}	
	while(!st.empty()){
		cout << st.top() << ' ';
		st.pop();
	}
	return 0;
}
