#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> res;

void backtrack(int n, int fr, int to, int via){
	if(n == 0) return;
	
	backtrack(n - 1, fr, via, to);
	res.push_back({fr, to});
	backtrack(n - 1, via, to, fr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    backtrack(n, 1, 3, 2);
    cout << res.size() << '\n';
    for(auto &x : res){
    	cout << x.first << " " << x.second << '\n';
	}

    return 0;
}
