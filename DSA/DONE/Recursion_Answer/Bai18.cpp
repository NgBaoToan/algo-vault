#include <bits/stdc++.h>
using namespace std;

long long n;

long long totalEven(long long n, long long total){
	if(n <= 0){
		return total;
	}
	
	if(n % 2 == 0) total += n % 10;
	
	return totalEven(n / 10, total);
}

long long totalOdd(long long n, long long total){
	if(n <= 0){
		return total;
	}
	
	if(n % 2 == 1) total += n % 10;
	
	return totalOdd(n / 10, total);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		cin >> n;
		cout << totalEven(n, 0) << '\n' << totalOdd(n, 0);
	return 0;
}