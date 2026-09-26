#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[10000001];

bool check(long long mid){
    long long sum = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(sum >= mid){
            cnt++;
            sum = 0;
        }
    }
    return cnt >= k + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        cin >> n >> k;
        long long l = 0;
        long long r = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            r += a[i];
        }
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
