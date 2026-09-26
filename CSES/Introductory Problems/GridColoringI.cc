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

    int n, m; cin >> n >> m;    
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            if((i + j) % 2 == 0){
                if(s[j] == 'A') cout << 'B';
                else cout << 'A';
            }else{
                if(s[j] == 'C') cout << 'D';
                else cout << 'C';
            }
        }
        cout << '\n';

    }
    
    return 0;   
}
