#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
long long bestX = 0, bestY = 0;

void update(long long x, long long y){
	if(x <= 0 || y <= 0){
		return;
	}

	long long cur = x * y;
	if(cur > ans){
		ans = cur;
		bestX = x;
		bestY = y;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> a(4);
	for(int i = 0; i < 4; i++){
		int x; cin >> x;
		a[i] = x;
	}

	sort(a.rbegin(), a.rend());

	//th1 lay quy thu 1
	update(a[0] / 4, a[0] / 4);
	//th2 lay thu 1 va thu 2
	for(int i = 1; i < 4; i++){
		update(a[0] / 4, a[i]);
	}

	for(int i = 1; i < 4; i++){
		update(a[0] / 3, a[i]);
	}

	for(int i = 1; i < 4; i++){
		update(a[0] / 2, a[i]);
	}

	if(a[1] >= a[2]){
		long long x = a[0] / 2;
		update(x, a[2]);
	}

	cout << bestX << ' ' << bestY;
	return 0;
}