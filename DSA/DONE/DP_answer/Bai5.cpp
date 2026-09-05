#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

const int MAXN = 1e6 + 5;
bool is_prime[MAXN];
int pref[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i < MAXN; i++){
    	if(is_prime[i]){
    		for(int j = i * i; j < MAXN; j += i) is_prime[j] = false;
    	}
    }

    for(int i = 1; i < MAXN; i++){
    	pref[i] = pref[i - 1] + is_prime[i];
    }

    int t; cin >> t;
    while(t--){
    	int l, r; cin >> l >> r;
    	if(l == 0) cout << pref[r] << '\n';
    	else cout << pref[r] - pref[l - 1] << '\n';
    }
    return 0;   
}
