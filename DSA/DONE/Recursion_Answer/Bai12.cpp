#include <bits/stdc++.h>
using namespace std;

string decToHex(long long n){
	if(n == 0) return "";
	
	int rem = n % 16;
	
	char hex = (rem < 10) ? (rem + '0') : (rem - 10 + 'A');
	
	return decToHex(n / 16) + hex;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long n; cin >> n;
	cout << decToHex(n) << '\n';
	return 0;
}