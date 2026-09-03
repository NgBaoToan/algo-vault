#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n, k, s, ans = 0;

void backtrack(int i, int cnt, int sum){
    if(cnt == k){
        if(sum == s) ans++;
        return;
    }

    if(sum > s) return;
    if(i > n) return;
    if(cnt + (n - i + 1) < k) return;

    backtrack(i + 1, cnt + 1, sum + i);

    backtrack(i + 1, cnt, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k >> s;
    backtrack(1, 0, 0);

    cout << ans << '\n';
    return 0;   
}
