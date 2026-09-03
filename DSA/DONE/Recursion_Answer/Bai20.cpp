#include <bits/stdc++.h>
using namespace std;

int n;

int count(int n){
	if(n == 1) return 0;
	
	int op1 = 1e9, op2 = 1e9, op3 = 1e9;
	
	if(n % 2 == 0){
		op1 = count(n / 2);
	}
	
	if(n % 3 == 0){
		op2 = count(n / 3);
	}
	
	op3 = count(n - 1);
	
	return min({op1, op2, op3}) + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		cin >> n;
		cout << count(n) << '\n';
	return 0;
}