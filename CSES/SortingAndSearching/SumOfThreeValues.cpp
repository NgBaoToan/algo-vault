#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x;
	vector<pair<int, int>> a;
	for(int i = 0; i < n; i++){
		int t; cin >> t;
		a.push_back({t, i + 1});
	}

	sort(a.begin(), a.end());

	for(int i = 0; i < n - 1; i++){
		int l = i + 1;
		int r = n - 1;
		while(l < r){
			long long sum = a[i].first + a[r].first + a[l].first;
			if(sum == x){
				cout << a[i].second << ' ' << a[l].second << " " << a[r].second << '\n';
				return 0;
			}else if(sum > x){
				r--;
			}else{
				l++;
			}
		}
	}

	cout << "IMPOSSIBLE\n";
	return 0;
}