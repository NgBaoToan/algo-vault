#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n, m;
int a[15][15];
int path = 0;

void backtrack(int i, int j){
    if(i == n && j == m){
        path++;
        return;
    }

    if(i < n) backtrack(i + 1, j);
    if(j < m) backtrack(i, j + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    backtrack(1, 1);
    cout << path << '\n';
    return 0;   
}
