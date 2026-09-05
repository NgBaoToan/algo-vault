#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[10000005];

bool check(long long m){
    long long total = 0;
    for(int i = 0; i < n; i++){
        total += (a[i] / m);
        if(total >= k) return true;
    }
    return total >= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> a[i];

		long long l = 1;
		long long r = accumulate(a, a + n, 0LL);
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
