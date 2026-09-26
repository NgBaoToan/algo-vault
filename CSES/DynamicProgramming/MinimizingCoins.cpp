#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x;
	vector<int> coin(n);
	for(int i = 0; i < n; i++){
		cin >> coin[i];
	}

	vector<int> dp(x + 1, 1e9);
	dp[0] = 0;

	for(int i = 1; i <= x; i++){
		for(int c : coin){
			if(i - c >= 0) dp[i] = min(dp[i], dp[i - c] + 1);
		}
	}

	if(dp[x] == 1e9) cout << -1 << '\n';
	else cout << dp[x] << '\n';

	return 0;
}