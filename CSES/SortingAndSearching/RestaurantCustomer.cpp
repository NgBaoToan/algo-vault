#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
    	int x, y; cin >> x >> y;
    	v.push_back({x, 1});
    	v.push_back({y, -1});
    }

    sort(v.begin(), v.end());
    int mx = -1;
    int cur = 0;
    for(auto [x, y] : v){
    	cur += y;
    	if(cur > mx){
    		mx = cur;
    	}
    }

    cout << mx << '\n';
    return 0;   
}
