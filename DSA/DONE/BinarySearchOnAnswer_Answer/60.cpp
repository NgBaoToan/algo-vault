#include <bits/stdc++.h>
using namespace std;

long long n, k; 
long long A[1000001];

bool check(long long mid){
	int cnt = 1;
	long long lastPost = A[0];
	for(int i = 1; i < n; i++){
		if(A[i] - lastPost >= mid){
			cnt++;
			lastPost = A[i];
		}
	}
	return cnt >= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> A[i];
		
		sort(A, A + n);
		
		long long l = 0;
		long long r = *max_element(A, A + n);
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
