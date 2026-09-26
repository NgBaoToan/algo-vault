#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, a, b; cin >> n >> a >> b;
	vector<int> x(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}

	vector<long long> S(n + 1, 0);
	long long mx = -1e18;

	for(int i = 1; i <= n; i++){
		S[i] = S[i - 1] + x[i];
	}

	deque<int> q;
	for(int i = a; i <= n; i++){
		int k = i - a;
		while(!q.empty() && S[q.back()] >= S[k]) q.pop_back();
		q.push_back(k);
		while(!q.empty() && q.front() < i - b) q.pop_front();
		mx = max(mx, S[i] - S[q.front()]);
	}

	cout << mx << '\n';

	return 0;
}