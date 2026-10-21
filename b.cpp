#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define ll long long
#define ull unsigned long long
#define ld long double
#define db double
#define int64 int64_t
#define int128 __int128

#define ar array
#define vt vector

#define ii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define vpll vector<pll>

#define ft first
#define sd second

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = (1LL << 62);
const ld EPS = 1e-9;
const ld PI = acos(-1.0L);

int main() {
    fast_io;

    int n;
    cin >> n;

    vector<int> dp(3, 0);

    int a, b, c; cin >> a >> b >> c;

    dp[0] = a;
    dp[1] = b;
    dp[2] = c;

    for(int i = 1; i < n; i++){
        int a, b, c; cin >> a >> b >> c;

        dp[0] = max(dp[0] + )
    }

    return 0;
}