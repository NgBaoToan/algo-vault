#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

	vector<long long> dp(n + 1, 0);
	dp[0] = a[0];
	dp[1] = max(dp[0], a[1]);
	
	for(int i = 2; i < n; i++){
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
	}
	
	cout << dp[n - 1] << '\n';
    return 0;
}
