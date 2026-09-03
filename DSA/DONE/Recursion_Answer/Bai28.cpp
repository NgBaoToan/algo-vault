#include <bits/stdc++.h>
using namespace std;

int lowerBound(int A[], int l, int r, int k, int res){
	if(l > r) return res;
	
	int m = l + (r - l) / 2;
	
	if(A[m] >= k) return lowerBound(A, l, m - 1, k, m);
	else return lowerBound(A, m + 1, r, k, res); 
}

int upperBound(int A[], int l, int r, int k, int res){
	if(l > r) return res;
	
	int m = l + (r - l) / 2;
	
	if(A[m] > k) return upperBound(A, l, m - 1, k, m);
	else return upperBound(A, m + 1, r, k, res);

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		int n; cin >> n;
		int A[n];
		for(int &x : A) cin >> x;
		int k; cin >> k;
		
		cout << upperBound(A, 0, n - 1, k, n) - lowerBound(A, 0, n - 1, k, n);
	return 0;
}