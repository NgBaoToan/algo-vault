#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int a[n + 1][n + 1];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = (i ^ j);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}