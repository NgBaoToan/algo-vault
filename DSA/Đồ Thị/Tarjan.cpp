/*
Dùng để kiểm tra đỉnh trụ (articulation point) trên đồ thị vô hướng bằng DFS low-link.

Ý tưởng low-link:
- disc[u]: thời điểm DFS lần đầu thăm u
- low[u]: disc nhỏ nhất mà u (hoặc cây con DFS của u) có thể "vươn tới"
          thông qua:
          + các cạnh cây DFS (tree-edge)
          + và tối đa 1 cạnh ngược (back-edge) về tổ tiên

Điều kiện đỉnh trụ:
- Nếu u không phải root:
    u là đỉnh trụ nếu tồn tại con v trong cây DFS sao cho low[v] >= disc[u]
- Nếu u là root:
    u là đỉnh trụ nếu root có >= 2 con trong cây DFS
*/

#include <bits/stdc++.h>
using namespace std;

#define nbaotoan ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int n, m, timer = 0;
vector<int> adj[1005];      // danh sách kề (đồ thị vô hướng)
int disc[1005], low[1005];  // disc: thời gian vào DFS, low: low-link
int vis[1005], AP[1005];    // vis: đã thăm, AP[u]=1 nếu u là đỉnh trụ

void init(){
    cin >> n >> m;

    // đọc m cạnh của đồ thị vô hướng
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // reset trạng thái
    memset(vis, 0, sizeof(vis));
    memset(AP, 0, sizeof(AP));
    // (disc/low không cần memset nếu bạn chỉ dùng khi vis=1,
    //  nhưng có cũng không sao; timer sẽ tăng theo DFS)
}

/*
dfs(u, par):
- u: đỉnh đang duyệt
- par: cha của u trong cây DFS (để tránh coi cạnh quay về cha là back-edge)
*/
void dfs(int u, int par){
    vis[u] = 1;                      // đánh dấu đã thăm u
    disc[u] = low[u] = ++timer;      // set thời gian vào DFS và low ban đầu
    int child = 0;                   // số con của u trong cây DFS (quan trọng cho root)

    // duyệt các đỉnh kề v của u
    for(int v : adj[u]){
        // nếu v là cha trực tiếp của u trong DFS tree thì bỏ qua
        // (vì đồ thị vô hướng có cả u->par và par->u)
        if(v == par) continue;

        if(!vis[v]){
            // (1) tree-edge: v chưa thăm, trở thành con của u trong DFS tree
            dfs(v, u);
            ++child;

            // Sau khi DFS xong v, low[u] có thể cập nhật từ low[v]
            // vì u đi xuống subtree(v) rồi quay về tổ tiên bằng back-edge (nếu có)
            low[u] = min(low[u], low[v]);

            // Điều kiện đỉnh trụ cho u (u không phải root):
            // nếu subtree(v) không có đường back-edge lên tổ tiên của u
            // => low[v] >= disc[u] thì bỏ u ra sẽ tách component
            if(par != -1 && disc[u] <= low[v]){
                AP[u] = 1;
            }
        } else {
            // (2) back-edge: v đã thăm và v không phải parent của u
            // Khi gặp back-edge u -> v, ta cập nhật low[u] bằng disc[v]
            // (disc[v] là thời điểm của một tổ tiên hoặc đỉnh đã thăm trước đó).
            low[u] = min(low[u], disc[v]);
        }
    }

    // Điều kiện đỉnh trụ cho root:
    // Root là đỉnh trụ nếu nó có >= 2 con trong cây DFS
    // (vì bỏ root sẽ tách các nhánh con thành các thành phần khác nhau)
    if(par == -1 && child > 1) AP[u] = 1;
}

int main(){
    nbaotoan;
    init();

    // chạy DFS cho mọi thành phần liên thông
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, -1);  // i là root của một cây DFS
        }
    }

    // in các đỉnh trụ
    for(int i = 1; i <= n; i++){
        if(AP[i]) cout << i << ' ';
    }
    return 0;
}

//cạnh cầu
/*
Tarjan tìm CẠNH CẦU (bridge) trên đồ thị vô hướng.

disc[u]: thời gian DFS vào u
low[u] : disc nhỏ nhất mà u hoặc cây con của u có thể chạm tới
         qua các cạnh cây DFS + back-edge

Bridge condition:
- Với tree-edge u -> v (v là con của u):
    (u, v) là cầu nếu low[v] > disc[u]
*/

// #include <bits/stdc++.h>
// using namespace std;

// #define nbaotoan ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

// int n, m, timer = 0;
// vector<int> adj[1005];
// int disc[1005], low[1005];
// int vis[1005];

// vector<pair<int,int>> bridges; // lưu danh sách các cạnh cầu

// void init(){
//     cin >> n >> m;

//     // nếu chỉ chạy 1 test thì không cần clear, nhưng để chắc chắn:
//     for(int i = 1; i <= n; i++) adj[i].clear();

//     for(int i = 0; i < m; i++){
//         int x, y; cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x); // vô hướng
//     }

//     memset(vis, 0, sizeof(vis));
//     memset(disc, 0, sizeof(disc));
//     memset(low, 0, sizeof(low));
//     timer = 0;
//     bridges.clear();
// }

// void dfs(int u, int par){
//     vis[u] = 1;
//     disc[u] = low[u] = ++timer; // gán thời gian vào DFS và low ban đầu

//     for(int v : adj[u]){
//         if(v == par) continue;   // bỏ cạnh quay về cha (đồ thị vô hướng)

//         if(!vis[v]){
//             // (1) tree-edge: v chưa thăm
//             dfs(v, u);

//             // cập nhật low của u từ low của con v
//             low[u] = min(low[u], low[v]);

//             // (u, v) là cầu nếu subtree(v) không quay về u/tổ tiên u được
//             if(low[v] > disc[u]){
//                 bridges.push_back({u, v});
//             }
//         } else {
//             // (2) back-edge: v đã thăm và không phải cha
//             // cập nhật low[u] bằng disc[v] (thời gian của tổ tiên/đỉnh đã thăm)
//             low[u] = min(low[u], disc[v]);
//         }
//     }
// }

// int main(){
//     nbaotoan;
//     init();

//     // chạy DFS cho mọi thành phần liên thông
//     for(int i = 1; i <= n; i++){
//         if(!vis[i]){
//             dfs(i, -1);
//         }
//     }

//     // in danh sách cầu
//     // (u, v) và (v, u) là cùng một cạnh vô hướng, ở đây lưu theo hướng DFS tree
//     for(auto &e : bridges){
//         cout << e.first << " " << e.second << "\n";
//     }

//     return 0;
// }
