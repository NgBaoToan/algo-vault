#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int A[], int l, int r, int k){
	if(l > r) return false;
	
	int m = l + (r - l) / 2;
	
	if(A[m] == k) return true;
	
	if(A[m] < k) return binarySearch(A, l, m - 1, k);
	
	return binarySearch(A, m + 1, r, k);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		int n;
		cin >> n;
		int A[n];
		for(int &x : A) cin >> x;
		int k; cin >> k;
		
		if(binarySearch(A, 0, n - 1, k)) cout << "YES\n";
		else cout << "NO\n";	
	return 0;
}