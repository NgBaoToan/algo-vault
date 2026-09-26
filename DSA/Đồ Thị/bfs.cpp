#include <bits/stdc++.h>
using namespace std;
int n, m; 
vector<int> adj[200005];
int vis[200005];

void init(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	vis[u] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for(int y : adj[x]){
			if(!vis[y]){
				q.push(y);
				vis[y] = 1;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	nhap();
	bfs(s);
	return 0;
}