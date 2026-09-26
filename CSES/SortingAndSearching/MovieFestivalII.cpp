#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	vector<pair<int,int>> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), [](const auto &x, const auto &y){
		if(x.second == y.second) return x.first < y.first;
		return x.second < y.second;
	});

	multiset<int> end;
	for(int i = 0; i < k; i++) end.insert(0);

	int cnt = 0;
	for(int i = 0; i < n; i++){
		auto it = end.upper_bound(v[i].first);

		if(it != end.begin()){
			it--;
			end.erase(it);
			end.insert(v[i].second);
			cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}