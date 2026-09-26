#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	vector<long long> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	map<long long, long long> mp;

	int l = 0;
	long long ans = 0;
	int distinct = 0;

	for(int i = 0; i < n; i++){
		if(mp[a[i]] == 0) distinct++;
		mp[a[i]]++;
		while(distinct > k){
			mp[a[l]]--;

			if(mp[a[l]] == 0) distinct--;

			l++;
		}

		ans += i - l + 1;
	}

	cout << ans << '\n';
	return 0;
}