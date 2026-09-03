#include <bits/stdc++.h>
using namespace std;

long long n; 

long long findMax(long long n, int mx){
	if(n <= 0) return mx;
	if(mx < n % 10) mx = n % 10;
	return findMax(n / 10, mx);
}

long long findMin(long long n, int mn){
	if(n <= 0) return mn;
	if(mn > n % 10) mn = n % 10;
	return findMin(n / 10, mn);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		cin >> n;
		cout << findMax(n, -1e17) << ' ' << findMin(n, 1e17) << '\n';
	return 0;
}