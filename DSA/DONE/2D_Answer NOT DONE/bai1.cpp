#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define ll long long
#define arr array

bool isPrime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n == 3) return true;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m; cin >> n >> m;
    int a[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(isPrime(a[i][j])){
                cout << a[i][j] << '\n';
            }
        }
    }
    return 0;   
}
