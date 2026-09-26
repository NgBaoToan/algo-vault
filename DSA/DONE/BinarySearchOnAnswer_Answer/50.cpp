#include <bits/stdc++.h>
using namespace std;

long long n, x, y;

bool check(long long m){
    return  (m / x) + (m / y) >= n - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> y;
    long long l = 0;
    long long r = max(x, y) * n;
    long long ans = 0;
    while(l <= r){
        long long m = l + (r - l) / 2;
        if(check(m)){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }

    cout << ans + min(x, y);
    return 0;
}
