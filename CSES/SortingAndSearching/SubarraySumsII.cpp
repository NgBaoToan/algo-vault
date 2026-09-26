#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	map<long long, long long> mp;
	long long sum = 0;
	long long ans = 0;
	mp[0] = 1;

	for(int i = 0; i < n; i++){
		sum += a[i];
		ans += mp[sum - x];

		mp[sum]++;
	}

	cout << ans << '\n';
	return 0;
}