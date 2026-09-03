#include <bits/stdc++.h>

using namespace std;

long long n, k, a[1000001];

bool check(long long mid){
    long long cnt = 1;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + a[i] <= mid){
            sum += a[i];
        }else{
            cnt++;
            sum = a[i];
        }
    }

    return cnt <= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    long long l = 0, r = 0;
    for(int i = 0; i < n; i++){
        l = max(l, a[i]);
        r += a[i];
    }

    while(l < r){
        long long m = (l + r) / 2;
        if(check(m)){
            r = m;
        }else{
            l = m + 1;
        }
    }

    cout << l << '\n';

    return 0;
}
