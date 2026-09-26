#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
long long F[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    F[0] = 0, F[1] = 0, F[2] = 1;
    for(int i = 3; i < MAXN; i++){
        F[i] = (F[i - 1] + F[i - 2] + F[i - 3]) % MOD;
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << F[n] << '\n';
    }

    return 0;
}