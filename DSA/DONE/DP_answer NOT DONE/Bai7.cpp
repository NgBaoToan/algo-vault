#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

const int MAXN = 1e6 + 5;
long long a[MAXN], dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    	dp[1] = 0;
    if(n >= 2) dp[2] = abs(a[2] - a[1]);
    for(int i = 3; i <= n; i++){
    	dp[i] = min(dp[i - 1] * abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[n] << '\n';
    return 0;   
}
