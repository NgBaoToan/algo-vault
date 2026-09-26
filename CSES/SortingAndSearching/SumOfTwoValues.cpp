#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, x; cin >> n >> x;
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; i++){
    	ll a; cin >> a;
    	v.push_back({a, i + 1});
    }

    sort(v.begin(), v.end());

    ll l = 0;
    ll r = n - 1;
   	while(l < r){
   		ll sum = v[l].first + v[r].first;
   		if(sum == x){
   			cout << v[l].second << ' ' << v[r].second << '\n';
   			return 0;
   		} else if(sum > x) r--;
   		else l++;
   	}

   	cout << "IMPOSSIBLE" << '\n';
    return 0;   
}
