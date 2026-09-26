#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		int n, k; cin >> n >> k;
		vector<int> a(n);
		int total_ones = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] == 1){
				total_ones++;
			}
		}
		
		if(total_ones < k){
			cout << -1 << '\n';
			return 0;
		}
		
		int cur = 0;
		for(int i = 0; i < k; i++){
			if(a[i] == 1){
				cur++;
			}
		}
		
		int mxOnes = cur;
		for(int i = k; i < n; i++){
			cur += a[i]- a[i - k];
			if(cur > mxOnes){
				mxOnes = cur;
			}
		}
		
		cout << k - mxOnes << '\n';
	return 0; 
}