#include <bits/stdc++.h>
using namespace std;

struct Task{
	long long dur, dea;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<Task> t(n);
	for(int i = 0; i < n; i++){
		cin >> t[i].dur >> t[i].dea;
	}

	sort(t.begin(), t.end(), [](const auto& x, const auto &y){
		if(x.dur == y.dur) return x.dea < y.dea;
		return x.dur < y.dur;
	});

	long long cur = 0;
	long long total = 0;
	for(auto [x, y] : t){
		cur += x;
		total += y - cur;
	}

	cout << total << '\n';
	return 0;
}