#include <bits/stdc++.h>
#include <random>
#define taskname "FINDK1"

using namespace std;

using ll = long long;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r){
    return uniform_int_distribution<ll> (l, r)(rng);
}

ll RandDegit(int d, ll l, ll r){
    ll x = 0;
    for(int i = 1; i <= d; i++) x = x * 10LL + Rand((i == 1), 9);
    x = min(x, r);
    x = max(x, l);
    return x;
}

const int N = 101;
int n, k, a[N];

void gen(){
    n = Rand(1, 100);

    if(Rand(1, 4) == 1){
        k = Rand(1, 100);
        for(int i = 1; i <= n; i++){
            a[i] = k;
            while(a[i] == k) a[i] = Rand(1, 100);
        }
    }else{
        for(int i = 1; i <= n; i++){
            a[i] = Rand(1, 100);
        }
        k = a[Rand(1, n)];
    }

    cout << n << ' ' << k << '\n';
    for(int i = 1; i <= n; i++){
        cout << a[i] << (i == n ? "" : " ");
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen(taskname".inp", "w", stdout);
    gen();
}