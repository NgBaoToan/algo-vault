#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int a[9][9];
int mx = 0;

int col[20], d1[30], d2[30];

void backtrack(int i, int core){
    if(i > 8){
        mx = max(mx, core);
        return;
    }

    for(int j = 1; j <= 8; j++){
        if(!col[j] && !d1[i - j + 8] && !d2[i + j]){
            col[j] = d1[i - j + 8] = d2[i + j] = 1;

            backtrack(i + 1, core + a[i][j]);

            col[j] = d1[i - j + 8] = d2[i + j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            cin >> a[i][j];
        }
    }

    backtrack(1, 0);

    cout << mx << '\n';

    return 0;   
}
