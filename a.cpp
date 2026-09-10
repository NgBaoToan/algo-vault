#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e6 + 6;

#define ll long long
#define ld long double
#define ar array
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ft first
#define sd second
#define sz(x) (int)(x).size()

void solve(){
    ll x, y, k;
    cin >> x >> y >> k;

    ll D = y - x;
    ll ans = 0;
    for(ll i = 0; i < k; i++){
        if(x + i > D){
            ans += (k - i) * D;
            break;
        }
        ans += D % (x + i);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}
