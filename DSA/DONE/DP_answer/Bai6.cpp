#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
bool is_prime[MAXN];
long long pref[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAXN; j += i) is_prime[j] = false;
        }
    }

    pref[0] = 0; pref[1] = 0;
    long long cur = 1;
    bool has_prime = false;

    for(int i = 2; i < MAXN; i++){
    	if(is_prime[i]){
    		cur = (cur * i) % MOD;
    		has_prime = true;
    	}
    	pref[i] = has_prime ? cur : 0;
    }

    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	cout << pref[n] << '\n';
    }
    return 0;   
}
