#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int l, int m, int r){
	vector<int> tmp;
	int i = l;
	int j = m + 1;
	
	while(i <= m && j <= r){
		if(A[i] <= A[j]){
			tmp.push_back(A[i]);
			i++;
		}else{
			tmp.push_back(A[j]);
			j++;
		}
	}
	
	while(i <= m){
		tmp.push_back(A[i]);
		i++;
	}
	
	while(j <= r){
		tmp.push_back(A[j]);
		j++;
	}
	
	for(int k = 0; k < tmp.size(); k++){
		A[l + k] = tmp[k];
	}
}

void sort(int A[], int l, int r){
	if(l >= r) return;
	
	int m = l + (r - l) / 2;
	
	sort(A, l, m);
	sort(A, m + 1, r);
	
	merge(A, l, m, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		int n; cin >> n;
		int A[n];
		for(int &x : A) cin >> x;
		sort(A, 0, n - 1);
		
		for(int &x : A) cout << x << ' ';
	return 0;
}