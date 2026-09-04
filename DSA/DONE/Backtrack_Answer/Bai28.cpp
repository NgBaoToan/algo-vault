#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> cur;
void backtrack(int sum){
	if(sum == n){
		for(int i = 0; i < cur.size(); i++){
			cout << cur[i] << (i == cur.size() - 1 ? "" : " + ");
		}
		cout << '\n';
		return;
	}
	
	for(int j = 1; j <= n - sum; j++){
		cur.push_back(j);
		backtrack(sum + j);
		cur.pop_back();
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    backtrack(0);

    return 0;
}