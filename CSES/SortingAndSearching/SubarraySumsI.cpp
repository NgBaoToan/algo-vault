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

	long long cur = 0;
	int cnt = 0;
	int l = 0;
	for(int i = 0; i < n; i++){
		cur += a[i];
		
		while(cur > x){
			cur -= a[l++];
		}

		if(cur == x){
			cnt++;
			cur -= a[l++];
		}
	}

	cout << cnt << '\n';
	return 0;
}