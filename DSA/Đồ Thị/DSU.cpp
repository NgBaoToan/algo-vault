//DSU hay Disjion Set Union

#include <bits/stdc++.h>
using namespace std;
#define nbaotoan ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
int n, m;
int parent[1005];
int sz[1005]; //sz[i] : số phần tử trong tập hợp do i quản lý
void init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}
//Đi tìm người đại diện
//i = parent
int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
//Gộp
bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[v] < sz[u]){
        parent[v] = u;
        sz[u] += sz[v];
    }else{
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true;
}
int main(){
    nbaotoan;
    cin >> n >> m;
    init();
	   
    return 0;
}