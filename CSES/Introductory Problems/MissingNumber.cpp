#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n; cin >> n;
    long long total = 0;
    long long S = n * (n + 1) / 2;
    for(int i = 0; i < n - 1; i++){
    	int x; cin >> x;
    	total += x;
	}
	
	cout << S - total << '\n';
    return 0;
}