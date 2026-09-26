#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

ll a, b;

ll ucln(ll a, ll b){
    if(b == 0) return a;
    return ucln(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> a >> b;
    ll gcd = ucln(a, b);

    ll lcm = (a / gcd) * b;

    cout << gcd << ' ' << lcm << '\n';
    return 0;   
}
