#include <bits/stdc++.h>
using namespace std;

bool increasingArray(int A[], int i, int n){
	if(A[i] < A[i - 1]) return false;
	
	if(i == n - 1) return true;
	
	return increasingArray(A, i + 1, n);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		int n; cin >> n;
		int A[n];
		for(int &x : A) cin >> x;
		
		if(increasingArray(A, 1, n)) cout << "YES\n";
		else cout << "NO\n";
	return 0;
}