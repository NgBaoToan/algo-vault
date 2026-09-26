#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt = 0;
        int mx = -1;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(x > mx){
                mx = x;
                cnt = 1;
            }else if(x == mx){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;   
}
