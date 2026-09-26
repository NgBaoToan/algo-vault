#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n, k;

ll dq(int i, ll res){
	if(i > k) return res;
	return dq(i + 1, res * (n  - i + 1) / i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> k;

    cout << dq(1, 1LL) << '\n';

    return 0;   
}
