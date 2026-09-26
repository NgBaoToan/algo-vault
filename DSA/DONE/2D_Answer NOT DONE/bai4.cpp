#include <bits/stdc++.h>
using namespace std;

bool check(int n){
    if(n < 10) return true;
    string s = to_string(n);
    for(int i = 0; i < s.size(); i++){
        if(s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int a[n][n];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(check(a[i][j])) cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}