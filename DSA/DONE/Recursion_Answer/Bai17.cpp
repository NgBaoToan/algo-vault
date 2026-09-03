#include <bits/stdc++.h>
using namespace std;

long long n;

void leftToRight(long long n){
	if(n < 10){
		cout << n << ' ';
		return;
	}
	
	leftToRight(n / 10);
	
	cout << n % 10 << " ";
}

void rightToLeft(long long n){
	if(n < 10){
		cout << n << " ";
		return;
	}
	
	cout << n % 10 << " ";
	
	rightToLeft(n / 10);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		cin >> n;
		leftToRight(n);
		cout << '\n';
		rightToLeft(n);
	return 0;
}