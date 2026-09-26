#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll res = 1;
    for(int i = 0; i < n; i++){
    	if(a[i] > res){
    		break;
    	}
    	res += a[i];
    }

    cout << res << '\n';
    return 0;   
}