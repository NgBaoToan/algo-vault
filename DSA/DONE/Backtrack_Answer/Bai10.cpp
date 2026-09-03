#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n;
int c[20][20];
int cmin = 1e9;
int min_cost = 1e9;
int vis[20];

void backtrack(int u, int cnt, int cur){
    if(cur + (n - cnt + 1) * cmin >= min_cost){
        return;
    }

    if(cnt == n) {
        min_cost = min(min_cost, cur + c[u][1]);
        return;
    }

    for(int v = 2; v <= n; v++){
        if(!vis[v]){
            vis[v] = 1;
            backtrack(v, cnt + 1, cur + c[u][v]);
            vis[v] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            if(c[i][j] > 0){
                cmin = min(cmin, c[i][j]);
            }  
        }
    }

    vis[1] = 1;
    backtrack(1, 1, 0);
    cout << min_cost << '\n';
    return 0;   
}
