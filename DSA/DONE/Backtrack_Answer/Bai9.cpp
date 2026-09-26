#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n, S;
int t[100001];
int mnCnt = 1e9;

void backtrack(int i, int sum,int cnt){
    if(cnt > mnCnt) return;

    if(sum == S){
        mnCnt = min(mnCnt, cnt);
        return;
    }

    if(i == n || sum > S) return;

    backtrack(i + 1, sum + t[i], cnt + 1);

    backtrack(i + 1, sum, cnt);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> S;
    for(int &x : t) cin >> x;
    sort(t, t + n, greater<int>());

    backtrack(0, 0, 0);

    if(mnCnt == 1e9) cout << -1 << '\n';
    else cout << mnCnt << '\n';
    return 0;   
}
