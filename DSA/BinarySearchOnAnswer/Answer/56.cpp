#include <bits/stdc++.h>
using namespace std;

long long n, h;
long long a[1000007];

bool check(long long mid){
	long long total = 0;
	for(int i = 0; i < n; i++){
		total += (a[i] + mid - 1) / mid;
		if(total > h) return false;
	}
	return total <= h;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

        cin >> n >> h;
        for(int i = 0; i < n; i++) cin >> a[i];
		long long l = 0;
		long long r = *max_element(a, a + n);
		
		while(l < r){
			long long m = l + (r - l) / 2;
			if(check(m)){
				r = m;
			}else{
				l = m + 1;
			}
		}
		
		cout << l;
    return 0;
}
