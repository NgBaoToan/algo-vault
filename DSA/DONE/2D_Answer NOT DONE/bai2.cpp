#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

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
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    for(int j = 0; j < m; j++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i][j];
        }

        cout << sum << ' ';
    }

    return 0;   
}
