#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

const int MOD = 1e9 + 7;
long long C[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    C[0] = 1; C[1] = 1;
    for(int i = 2; i <= 1000; i++){
    	C[i] = 0;
    	for(int j = 0; j < i; j++){
    		C[i] = (C[i] + (C[j] * C[i - j - 1]) % MOD) % MOD;
    	}
    }

    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	cout << C[n] << '\n';
    }
    return 0;   
}
