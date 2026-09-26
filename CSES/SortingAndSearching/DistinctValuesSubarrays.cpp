#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int a[n];
	for(int &x : a) cin >> x;
	map<int, int> freq;
	int l = 0;

	long long ans = 0;
	for(int i = 0; i < n; i++){
		freq[a[i]]++;
		while(freq[a[i]] > 1){
			freq[a[l]]--;
			l++;
		}

		ans += i - l + 1;
	}

	cout << ans << '\n';
 
	return 0;
}