#include <bits/stdc++.h>
using namespace std;

long long n;

long long dq(long long n, long long total){
	if(n == 0) return total;
	total += n % 10;
	return dq(n / 10, total);
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
		cin >> n;
		cout << dq(n, 0) << '\n';
	return 0;
}