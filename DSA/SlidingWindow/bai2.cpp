#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	deque<int> min_dq, max_dq;
	for(int i = 0; i < n; i++){
		while(!min_dq.empty() && min_dq.front() <= i - k) min_dq.pop_front();
		while(!max_dq.empty() && max_dq.front() <= i - k) max_dq.pop_front();

		while(!min_dq.empty() && a[min_dq.back()] >= a[i]) min_dq.pop_back();
		while(!max_dq.empty() && a[max_dq.back()] <= a[i]) max_dq.pop_back();

		min_dq.push_back(i);
		max_dq.push_back(i);
		
		if(i >= k - 1){
			cout << a[min_dq.front()] << ' ' << a[max_dq.front()] << '\n';
		}
	}
 	return 0;	
}

