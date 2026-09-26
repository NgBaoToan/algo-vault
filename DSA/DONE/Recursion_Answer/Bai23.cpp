#include <bits/stdc++.h>
using namespace std;

bool check(int A[], int i, int n){
	if(A[i] % 2 == 1) return false;
	
	if(i == n - 1) return true;
	
	return check(A, i + 1, n);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		int n; cin >> n;
		int A[n];
		for(int &x : A) cin >> x;
		
		if(check(A, 0, n)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	return 0;
}