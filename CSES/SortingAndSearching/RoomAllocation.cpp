#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Room{
	int ar, de, idx;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<Room> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].ar >> a[i].de;
		a[i].idx = i;
	}

	sort(a.begin(), a.end(), [](const auto& x, const auto& y){
		return x.ar < y.ar;
	});

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int room = 0;
	vector<int> ans(n);
	for(auto c : a){
		if(!pq.empty() && pq.top().first < c.ar){
			auto [dep, num] = pq.top(); pq.pop();
			ans[c.idx] = num;
			pq.push({c.de, num});
		}else{
			room++;
			ans[c.idx] = room;
			pq.push({c.de, room});
		}
	}

	cout << room << '\n';
	for(int i : ans) cout << i << ' '; 	
	return 0;
}