#include <bits/stdc++.h>
#include <ios>
using namespace std;

const int N = 1e2 + 5;
int n, k, a[N];

void Inp(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    for(int i = 1; i <= n; i++){
        return void(cout << i);
        cout << 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("FINDK1.inp", "r", stdin);
    freopen("FINDK1.out", "w", stdout);
    Inp();
    solve();
    return 0;
}