#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	long long total = 0;
	long long mx = -1;
	for(int i = 0; i < n; i++){
		long long x; cin >> x;
		total += x;
		mx = max(mx, x);
	}

	if(total <= mx * 2) cout << mx * 2 << '\n';
	else cout << total << '\n';

	return 0;
}