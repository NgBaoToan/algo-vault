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
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(a != b){
            cout << "Happy Alex\n";
            return 0;
        }
    }

    cout << "Poor Alex\n";

    return 0;   
}
