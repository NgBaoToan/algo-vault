#include <bits/stdc++.h>
using namespace std;

long long n, l;
long long h[100000001];

bool check(long long mid){
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(h[i] - mid > 0)
            sum += h[i] - mid;
    }

    return sum >= l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;
    for(int i = 0; i < n; i++) cin >> h[i];

    long long l = 0;
    long long r = *max_element(h, h + n);
    long long ans = 0;
    while(l <= r){
        long long m = l + (r - l) / 2;
        if(check(m)){
            ans = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }

    cout << ans;
    return 0;
}
