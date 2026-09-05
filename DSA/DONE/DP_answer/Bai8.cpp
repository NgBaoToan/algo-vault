#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

const int MAXN = 1e6 + 5;
long long a[MAXN], dp[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[1] = 0;
	for(int i = 2; i <= n; i++){
		dp[i] = 1e18;
		for(int j = 1; j <= k; j++){
			if(i - j >= 1){
				dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
			}
		}
	}
	cout << dp[n] << '\n';
    return 0;   
}
