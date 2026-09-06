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
        vector<int> a(n);
        int sorted = 1;
        for(int i = 0; i < n; i++){
            cin >> a[i];

            if(i > 0 && a[i] < a[i - 1]){
                sorted = 0;
            }
        }

        if(!sorted){
            cout << 1 << '\n';
        }else{
            cout << n << '\n';
        }
    }

    return 0;   
}
