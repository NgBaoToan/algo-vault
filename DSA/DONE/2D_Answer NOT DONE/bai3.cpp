#include <bits/stdc++.h>
using namespace std;

int a[205][205];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    int min_val = 2e9;
    int max_val = -1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] > max_val) max_val = a[i][j];
            if(a[i][j] < min_val) min_val = a[i][j];
        }
    }

    cout << min_val << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == min_val){
                cout << i + 1 << ' ' << j + 1 << '\n';
            }
        }
    }

    cout << max_val << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == max_val){
                cout << i + 1 << ' ' << j + 1 << '\n';
            }
        }
    }
    return 0;
}