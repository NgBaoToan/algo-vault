#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	stack<int> st;

	for(int i = 1; i <= n; i++){
		while(!st.empty() && a[st.top()] >= a[i]) st.pop();

		if(st.empty()){
			cout << 0 << ' ';
		}else{
			cout << st.top() << ' ';
		}
		st.push(i);
	}


	return 0;
}