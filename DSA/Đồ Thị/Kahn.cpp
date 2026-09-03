//Thuật toán Kahn (xóa dần đỉnh)
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[200005];
int vis[200005];
int d[200005];
void init(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		d[y]++;
	}
}
void Kahn(){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(d[i] == 0) q.push(i);
	}
	while(!q.empty()){
		int x = q.front(); q.pop();
		cout << x << ' ';
		for(int y : adj[x]){
			--d[y];
			if(d[y] == 0) q.push(y);
		}
		//nếu cnt != n thì đồ thị có chu trì
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	Kahn();
	return 0;
}