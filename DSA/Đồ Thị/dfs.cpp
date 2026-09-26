#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1000000007;
const ll  INFLL = (ll)4e18;
const int INF = (int)2e9;
#define BIT(i) (1LL << (i))
#define MASK(x, i) (((x) >> (i)) & 1LL)
vector<int> adj[1000005];
int n, m, q;
int vis[1000005];
int cnt = 0;
void dfs(int u){
    vis[u] = cnt;
    for(int v : adj[u]){
        if(vis[v] == 0){
            dfs(v);
        }
    }
}

//Đếm xem đồ thị có bao nhiêu thành phần liên thông
int main() {
   fastio;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
	}
   return 0;
}