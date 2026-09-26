#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[1000001];

bool check(long long m){
	long long cnt = 0;

	for(int i = 0; i < n; i++){
		cnt += m / a[i];
		if(cnt >= k) return true;
	}

	return cnt >= k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	long long mx = -1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	sort(a, a + n);

	long long l = 0;
	long long r = mx * k;

	long long ans = 0;
	while(l <= r){
		long long m = l + (r - l) / 2;

		if(check(m)){
			ans = m;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}

	cout << ans << '\n';
	return 0;
}