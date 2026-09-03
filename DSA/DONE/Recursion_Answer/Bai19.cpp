#include <bits/stdc++.h>
using namespace std;

long long n;

bool check(long long n){
	if(n < 10){
		return n % 2 == 0;
	}
	
	return (n % 10 % 2 == 0) && check(n / 10);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
		cin >> n;
		cout << (check(n) ? "YES" : "NO");
	return 0;
}