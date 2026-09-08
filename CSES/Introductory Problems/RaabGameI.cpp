#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a, b; cin >> n >> a >> b;

    if(a + b > n){
        cout << "NO\n";
        return;
    }

    if(a + b > 0 && (a == 0 || b == 0)){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i++){
        cout << i << ' ';
    }

    cout << '\n';

    int k= n - a - b;
    vector<int> p2(n + 1);
    for(int i = 1; i <= k; i++){
        p2[i] = i;
    }

    int idx = k + 1;
    for(int i = k + a + 1; i <= n; i++){
        p2[idx++] = i;
    }

    for(int i = k + 1; i <= k + a; i++){
        p2[idx++] = i;
    }

    for(int i = 1; i <= n; i++){
        cout << p2[i] << ' ';
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
