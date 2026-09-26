#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[n][m];
    int mx_side = -1e9;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin >> a[i][j];
    		if(a[i][j] == 1){
    			dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
    			mx_side = max(mx_side, dp[i][j]);
			}
			
		}
	}
	
	cout << mx_side * mx_side << '\n';
    return 0;
}
