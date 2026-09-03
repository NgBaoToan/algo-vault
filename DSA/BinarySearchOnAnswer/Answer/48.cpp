#include <bits/stdc++.h>
using namespace std;

long long a, b, n;

bool check(long long m){
    long long x = m / a;
    long long y = m / b;
    return x * y >= n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        cin >> a >> b >> n;
        long long l = 0;
        long long r = 1;
        while(!check(r)) r <<= 1;
        
        long long res = -1;
        while(l <= r){
        	long long m = l + (r - l) / 2;
        	if(check(m)){
        		res = m;
        		r = m - 1;
			}else{
				l = m + 1;
			}
		}
		
		cout << res << '\n';
    return 0;
}
