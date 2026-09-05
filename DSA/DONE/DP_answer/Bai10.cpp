#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

const int MOD = 1e9 + 7;
long long dp[1005][1005];
char a[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin >> a[i][j];
    		dp[i][j] = 0;
    	}
    }

    if(a[1][1] == '*') dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(i == 1 && j == 1) continue;
    		if(a[i][j] == 'x'){
    			dp[i][j] = 0;
    		}else{
    			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    		}
    	}
    }

    cout << dp[n][m] << '\n';
    return 0;   
}
