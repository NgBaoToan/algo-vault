#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<pair<int, int>> adj[1005];

void input(){
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
}

void Dijkstra(int s){
	vector<int> d(n + 1, 1e9);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push({0, s});
	while(!Q.empty()){
		pair<int, int> p = Q.top(); Q.pop();
		int dis = p.first;
		int u = p.second;
		if(dis > d[u]) continue;
		for(auto e : adj[u]){
			int v = e.first;
			int w = e.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << d[i] << ' ';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	Dijkstra(s);
	return 0;
}