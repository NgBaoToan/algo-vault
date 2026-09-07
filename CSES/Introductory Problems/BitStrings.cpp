#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n; cin >> n;
	long long res = 1;
	for(int i = 1; i <= n; i++){
		res = (res * 2) % MOD;
	}
	
	cout << res << '\n';
	
    return 0;
}