#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n, check;
int a[101][101];

void backtrack(int i, int j, string path){
    if(i == n && j == n){
        check = 1;
        cout << path << '\n';
        return;
    }

    if(i + 1 <= n && a[i + 1][j] == 1){
        backtrack(i + 1, j, path + "D");
    }

    if(j + 1 <= n && a[i][j + 1] == 1){
        backtrack(i, j + 1, path + "R");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    backtrack(1, 1, "");

    if(check == 0){
        cout << -1 << '\n';
    }
    return 0;   
}
