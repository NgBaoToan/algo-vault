#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int a[n];

	for(int &x : a) cin >> x;

	sort(a, a + n);

	long long ans = 1;
	int cnt = 1;
	for(int i = 0; i < n - 1; i++){
		if(a[i] == a[i + 1]) cnt++;
		else{
			ans = (ans * (cnt + 1)) % MOD;
			cnt = 1;
		}
	}

	ans = (ans * (cnt + 1)) % MOD;
	ans = (ans - 1) % MOD;

	cout << ans << '\n';

	return 0;
}