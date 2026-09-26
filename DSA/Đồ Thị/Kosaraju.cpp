/*
B1: Xét đồ thị ban đầu lấy thứ tự sắp xếp topo
B2: Tạo ra đồ thị lật ngược
B3: pop lần lược cách đỉnh trong ngăn xếp và gọi dfs từ đỉnh đó

Nếu chỉ có 1 ttlt thì đồ thị có 1 thành phần liên thông mạnh
*/

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[100001], t_adj[100001];
int vis[100001];
stack<int> st;
void init(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        t_adj[y].push_back(x);
    }
}
void dfs1(int u){
    vis[u] = 1;
    for(int v : t_adj[u]){
        if(!vis[v]){
            dfs1(v);
        }
    }
    st.push(u);
}
void dfs2(int u){
    cout << u << ' ';
    vis[u] = 1;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs2(v);
        }
    }
}
void Kosoraju(){
    for(int i = 1; i  <= n; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!vis[u]){
            dfs2(u);
            cout << '\n';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    Kosoraju();
    return 0;
}