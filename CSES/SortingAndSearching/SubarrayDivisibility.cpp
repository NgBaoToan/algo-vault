#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<long long> cnt(n, 0);
	cnt[0] = 1;

	long long sum = 0;
	long long ans = 0;
	for(int i = 0; i < n; i++){

		int x; cin >> x;
		sum += x;
		long long rem = (sum % n + n) % n;
		ans += cnt[rem];
		cnt[rem]++;
	}

	cout << ans << '\n';

	return 0;
}