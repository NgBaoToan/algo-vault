#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e9;
long long fact[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << fact[n] << '\n';
    }

    return 0;
}