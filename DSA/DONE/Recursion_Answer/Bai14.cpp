#include <bits/stdc++.h>

using namespace std;

long long n;

long long dq(long long n, long long cnt){
	if(n <= 0) return cnt;
	cnt++;
	n /= 10;
	return dq(n, cnt); 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		cin >> n;
		cout << dq(n, 0) << '\n';
	return 0;
}