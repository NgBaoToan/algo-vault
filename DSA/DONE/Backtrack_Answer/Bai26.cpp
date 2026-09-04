#include <bits/stdc++.h>
using namespace std;

int n;
char a[10][10];
int vis[10][10];
string max_str = "";

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool cmp(const string& s1, const string& s2){
	if(s1.length() != s2.length()) return s1.length() > s2.length();
	return s1 > s2;
}

void dfs(int x, int y, string cur){
	if(x == n - 1 && y == n - 1){
		if(max_str == "" || cmp(cur, max_str)){
			max_str = cur;
		}
		return;
	}

	for(int k = 0; k < 4; k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]){
			vis[nx][ny] = 1;
			dfs(nx, ny, cur + a[nx][ny]);
			vis[nx][ny] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) cin >> a[i][j];
	}

	string st_str = "";
	st_str += a[0][0];
	vis[0][0] = 1;

	dfs(0, 0, st_str);
	cout << max_str << '\n';

	return 0;
}