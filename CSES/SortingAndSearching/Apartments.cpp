#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k; cin >> n >> m >> k;
    multiset<ll> a;
    vector<ll> b(m);

    for(int i = 0; i < n; i++){
    	int x; cin >> x;
    	a.insert(x);
    }

    for(int i = 0; i < m; i++){
    	cin >> b[i];
    }

    sort(b.begin(), b.end());
    int ans = 0;
    for(ll &x : b){
    	auto it = a.lower_bound(x - k);
    	if(it != a.end() && *it <= x + k){
    		ans++;
    		a.erase(it);
    	}
    }

    cout << ans << '\n';

    return 0;   
}
