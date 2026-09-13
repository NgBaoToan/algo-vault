#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
    	cin >> a[i];
	}
	
	vector<long long> dp(n + 1, 0);
	dp[0] = a[0];
	dp[1] = min(a[0], a[1]);
	for(int i = 2; i <= n; i++){
		dp[i] = min(dp[i - 1] + a[i - 1], dp[i - 2] + a[i - 2]);
	}
	
	cout << dp[n] << '\n';
    return 0;
}
