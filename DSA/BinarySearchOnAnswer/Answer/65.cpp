#include <bits/stdc++.h>
using namespace std;

long long n, k, a[1000001];

bool check(long long m){
    long long sum = 0;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if(a[i] > m) return false;
        if(sum + a[i] > m){
            sum = a[i];
            cnt++;
        }else{
            sum += a[i];
        }
    }

    return cnt <= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long l = 0;
    long long r = accumulate(a, a + n, 0LL);
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

    cout << ans << '\n';
    return 0;
}
