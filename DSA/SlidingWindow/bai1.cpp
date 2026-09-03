#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int current_sum = 0;
	for(int i = 0; i < k; i++) current_sum += a[i];

	ll max_sum = current_sum;
	int st = 0;
	for(int i = k; i < n; i++){
		current_sum = current_sum - a[i - k] + a[i];
		if(current_sum > max_sum){
			max_sum = current_sum;
			st = i - k + 1;
		}
	}

	cout << max_sum << '\n';
	for(int i = 0; i < k; i++){
		cout << a[st + i] << ' ';
	}
 	return 0;	
}

