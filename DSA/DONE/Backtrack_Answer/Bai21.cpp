#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[10][10];
string s;
int vis[10][10];
int found = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int idx){
	if(found) return;
	if(idx == s.length() - 1){
		found = 1;
		return;
	}

	vis[x][y] = 1;
	for(int k = 0; k < 4; k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] == s[idx + 1]){
			dfs(nx, ny, idx + 1);
		}
	}
	vis[x][y] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	cin >> s;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == s[0] && !found){
				dfs(i, j, 0);
			}
		}
	}

	if(found) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}