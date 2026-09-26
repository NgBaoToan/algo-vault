//có thể áp dụng có cạnh âm, nhưng không có chu trình âm
#include <bits/stdc++.h>
using namespace std;

struct edge{
	int x, y, w;	
};

int n, m, s;
vector<edge> dsc;
void input(){
	cin >> n >> m >> s;
	for(int i = 0; i< m; i++){
		int x, y, w; cin >> x >> y >> w;
		dsc.push_back({x, y, w});
		dsc.push_back({y, x, w});
	}
}

void BellmanFord(int s){
	vector<int> d(n + 1, 1e9);
	d[s] = 0;
	for(int i = 0; i < n - 1; i++){
		for(edge e : dsc){
			int u = e.x, v = e.y, w = e.w;
			if(d[u] != 1e9){
				d[v] = min(d[v], d[u] + w);
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
	BellmanFord(s);
	return 0;
}