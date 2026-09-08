#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n; cin >> n;
    int cnt = 0;
    while(n > 0){
    	cnt += n / 5;
    	n /= 5;
	}
	
	cout << cnt << '\n';
	
    return 0;
}
