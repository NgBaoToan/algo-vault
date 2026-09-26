#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int a[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    cout << "Pattern 1:" << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "Pattern 2:" << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[j][i] << ' ';
        }
        cout << '\n';
    }

    cout << "Pattern 3:" << '\n';
    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "Pattern 4:" << '\n';
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}