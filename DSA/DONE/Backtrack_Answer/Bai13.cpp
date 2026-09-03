#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define ll long long
#define arr array

int n, a[101], used[101];

void backtrack(int i){
    for(int j = 1; j <= n; j++){
        if(!used[j]){
            if(i > 1 && abs(j - a[i - 1]) == 1) continue;
            a[i] = j;
            used[j] = 1;

            if(i == n){
                for(int k = 1; k <= n; k++) cout << a[k];
                    cout << '\n';
            }else{
                backtrack(i + 1);
            }
            used[j] = 0;
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

    return 0;   
}
