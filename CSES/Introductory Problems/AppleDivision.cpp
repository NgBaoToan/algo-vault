#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    int mn = 1e9;
    long long total = 0;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	total += a[i];
	}
	
	for(int mask = 0; mask < (1 << n); mask++){
		long long cur = 0;
		for(int i = 0; i < n; i++){
			if(mask & (1 << i)){
				cur += a[i];
			}
		}
		
		long long diff = abs(total - 2 * cur);
		if(diff < mn){
			mn = diff;
		}
	}
	
	cout << mn << '\n';
    return 0;
}
