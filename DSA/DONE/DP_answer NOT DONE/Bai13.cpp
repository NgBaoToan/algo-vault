#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> freq(10005, 0);
    int mx_ele_val = 0;
    for(int i = 0; i < n; i++){
    	long long x; cin >> x;
    	freq[x] += x;
    	if(x > mx_ele_val){
    		mx_ele_val = x;
		}
	}

	vector<long long> dp(mx_ele_val + 1, 0);
	if(mx_ele_val >= 1) dp[1] = freq[1];
	for(int i = 2; i <= mx_ele_val; i++){
		dp[i] = max(dp[i - 1], dp[i - 2] + freq[i]);
	}
	
	cout << dp[mx_ele_val] << '\n';
    return 0;
}
