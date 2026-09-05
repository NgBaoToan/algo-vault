#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[10000007];

bool check(double m){
    if(m <= 0) return false;
    long long cur = 0.0;
    for(int i = 0; i < n; i++){
        cur += (__int128_t) (a[i] / m);
        if(cur >= k){
            return true;
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> a[i];

    double l = 0.0;
    double r = (double) *max_element(a, a + n);

    int cnt = 100;
    while(cnt--){
        double m = l + (r - l) / 2.0;
        if(check(m)){
            l = m;
        }else{
            r = m;
        }
    }
    cout << fixed << setprecision(6) << l;
    return 0;
}
