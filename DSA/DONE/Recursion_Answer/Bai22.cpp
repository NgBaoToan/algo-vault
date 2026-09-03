#include <bits/stdc++.h>
using namespace std;

void leftToRight(int a[], int i, int n){
	if(i == n - 1){
		cout << a[i];
		return;
	}
	
	cout << a[i++] << ' ';
	leftToRight(a, i, n);
}

void rightToLeft(int a[], int i, int n){
	if(i == 0){
		cout << a[i];
		return;
	}
	
	cout << a[i--] << ' ';
	rightToLeft(a, i, n);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		
		int n; cin >> n;
		int a[n];
		for(int &x : a) cin >> x;
		
		leftToRight(a, 0, n);
		cout << '\n';
		rightToLeft(a, n - 1, n);
	return 0;
}