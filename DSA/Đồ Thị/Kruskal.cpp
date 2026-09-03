//Cây khung là đồ thị kết nối tất cả các đỉnh trên đồ thị cạnh = đỉnh - 1
//Cây khung là đồ thị liên thông
//Cây khung không nên có chu trình
//Kruskal dùng để tìm cây khung cực tiểu
#include <bits/stdc++.h>
using namespace std;

struct edge{
    int x, y, w;
};

int n, m;
int par[1005], sz[1005];
vector<edge> dsc;
int vis[1005];
void init(){
    for(int i = 1; i <= n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int Find(int u){
    if(u == par[u]) return u;
    return par[u] = Find(par[u]);
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]){
        par[u] = v;
        sz[v] += sz[u];
    }else{
        par[v] = u;
        sz[u] += sz[v];
    }
    return true;
}

void Kruskal(){
	sort(dsc.begin(), dsc.end(), [](edge a, edge b){
		return a.w < b.w;
	});
	vector<edge> mst;
	long long d = 0;
	for(int i = 0; i < m; i++){
		if((int) mst.size() == n - 1) break;
		if(Union(dsc[i].x, dsc[i].y)){
			d += dsc[i].w;
			mst.push_back(dsc[i]);
		}
	}
	if((int) mst.size() < n - 1){
		cout << "IMPOSSIBLE\n";
	}else{
		cout << d << '\n';
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        dsc.push_back({x, y, w});
    }
    Kruskal();
    return 0;
}