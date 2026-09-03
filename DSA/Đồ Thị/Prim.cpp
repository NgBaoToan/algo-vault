//Prim chỉ chọn 1 đỉnh trong cây khung và một đỉnh nằm ngoài cây khung
//Dùng hàng đợi ưu tiên để chọn cạnh ngắn nhất

#include <bits/stdc++.h>
using namespace std;

struct edge{
	int x, y, w;
};

int n, m;
vector<pair<int, int>> adj[1005];
int used[1005];
void init(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
}

void Prim(int s){
	used[s] = 1;
	priority_queue<pair<int, int> ,vector<pair<int, int>>, greater<pair<int, int>>> Q;
	for(auto e : adj[s]){
		Q.push({e.second, e.first});
	}
	long long d = 0;
	int cnt = 1;
	while(!Q.empty()){
		//Cạnh ngắn nhất
		pair<int, int> p = Q.top(); Q.pop();
		//p.first = trọng số, p.second = đỉnh
		int w = p.first, u = p.second;
		if(used[u]) continue;
		d += w;
		used[u] = 1;
		++cnt;
		for(auto e : adj[u]){
			if(used[e.first] == 0){
				Q.push({e.second, e.first});
			}
		}
	}
	if(cnt == n){
		cout << d << '\n';
	}else{
		cout << "IMPOSSIBLE\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	Prim(1);
	return 0;
}