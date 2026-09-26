#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

	int cnt = 0;
	int l = 0;
	int r = n - 1;
	while(l <= r){
		if(l == r){
			cnt++;
			break;
		}else if(a[l] + a[r] <= x){
			cnt++;
			l++;
			r--;
		}else{
			r--;
			cnt++;
		}
	}

	cout << cnt << '\n';
    return 0;   
}
