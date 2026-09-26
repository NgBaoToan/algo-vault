#include <bits/stdc++.h>
using namespace std;

int n, a[20];
vector<int> cur;
vector<vector<int>> res;

void backtrack(int i, int sum){
	if(i == n){
		if(sum % 2 != 0 && !cur.empty()) res.push_back(cur);
		return;
	}

	backtrack(i + 1, sum);
	cur.push_back(a[i]);
	backtrack(i + 1, sum + a[i]);
	cur.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int &x : a) cin >> x;
	backtrack(0, 0);
	if(res.empty()){
		cout << "NOT FOUND" << '\n';
	}else{
		sort(res.begin(), res.end());
		for(auto& v : res){
			for(int x : v) cout << x << ' ';
			cout << '\n';
		}
	}

	return 0;
}