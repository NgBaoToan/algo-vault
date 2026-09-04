#include <bits/stdc++.h>
using namespace std;

int n, k;
string s, cur = "";

void backtrack(int st){
	if(cur.length() == k){
		cout << cur << '\n';
		return;
	}

	for(int i = st; i < n; i++){
		cur.push_back(s[i]);
		backtrack(i);
		cur.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k >> s;
	sort(s.begin(), s.end());
	backtrack(0);

	return 0;
}