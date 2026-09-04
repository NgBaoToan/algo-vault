#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> cur;
vector<vector<int>> res;

void backtrack(int val, int sum){
	if(sum == n){
		res.push_back(cur);
		return;
	}
	
	int p = pow(val, k);
	if(sum + p <= n){
		cur.push_back(val);
		backtrack(val + 1, sum + p);
		cur.pop_back();
		backtrack(val + 1, sum);
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    backtrack(1, 0);
    cout << res.size() << '\n';
    sort(res.begin(), res.end());
    for(auto & v : res){
    	for(int i = 0; i < v.size(); i++){
    		cout << v[i] << "^" << k << (i == v.size() - 1 ? "" : " + ");
		}
		cout << '\n';
	}


    return 0;
}