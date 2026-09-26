#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[15][15];
int vis[15][15];
int min_cost = INT_MAX;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void backtrack(int r, int c, int cost){
	if(cost >= min_cost) return;
	
	if(r == n - 1 && c == m - 1){
		min_cost = min(min_cost, cost);
		return;
	}
	
	for(int k = 0; k < 4; k++){
		int nr = r + dx[k];
		int nc = c + dy[k];
		
		if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
			vis[nr][nc] = 1;
			backtrack(nr, nc, cost + a[nr][nc]);
			vis[nr][nc] = 0;
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++) cin >> a[i][j];
    	
    vis[0][0] = 1;
    backtrack(0, 0, a[0][0]);
    cout << min_cost << '\n';

    return 0;
}