#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	ll n; cin >> n;
	ll cur = 0;
	ll mx = -1e18;
	for(int i = 0; i < n; i++){
		ll x; cin >> x;
		cur = max(x, cur + x);
		if(cur > mx){
			mx = cur;
		}
	}

	cout << mx << '\n';

    return 0;   
}
