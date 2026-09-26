#include <bits/stdc++.h>
using namespace std;

struct Range{
	long long x, y;
	int idx;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<Range> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].x >> a[i].y;
		a[i].idx = i;
	}

	sort(a.begin(), a.end(), [](const auto &A, const auto &B){
		if(A.x == B.x) return A.y > B.y;
		return A.x < B.x;
	});

	vector<int> contains(n, 0);
	vector<int> contained(n, 0);

	long long mxY = -1;
	for(int i = 0; i < n; i++){
		if(a[i].y <= mxY){
			contained[a[i].idx] = 1;
		}
		mxY = max(mxY, a[i].y);
	}

	long long mnY = LLONG_MAX;
	for(int i = n - 1; i >= 0; i--){
		if(a[i].y >= mnY){
			contains[a[i].idx] = 1;
		}

		mnY = min(mnY, a[i].y);
	}

	for(int &x : contains){
		cout << x << ' ';
	}

	cout << '\n';
	for(int &x : contained){
		cout << x << ' ';
	}
	return 0;
}