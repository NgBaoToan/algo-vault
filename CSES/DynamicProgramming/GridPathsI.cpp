#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n;
char c[1001][1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> c[i][j];
		}
	}

	dp[0][0] = 1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(c[i][j] == '*'){
				dp[i][j] = 0;
			}else{
				if(i > 0) dp[i][j] += dp[i - 1][j];
				if(j > 0) dp[i][j] += dp[i][j - 1];
				dp[i][j] %= MOD;
			}
		}
	}

	cout << dp[n - 1][n - 1] << '\n';
	return 0;
}