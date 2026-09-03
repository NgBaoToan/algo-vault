#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n, ans = 0;

int col[20], d1[30], d2[30];

void backtrack(int i){
    if(i > n){
        ans++;
        return;
    }

    for(int j = 1; j <= n; j++){
        if(!col[j] && !d1[i - j + n] && !d2[i + j]){
            col[j] = d1[i - j + n] = d2[i + j] = 1;

            backtrack(i + 1);

            col[j] = d1[i - j + n] = d2[i + j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    backtrack(1);
    cout << ans << '\n';

    return 0;   
}
