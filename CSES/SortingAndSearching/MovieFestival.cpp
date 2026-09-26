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
    	v.push_back({x, y});
    }

    sort(v.begin(), v.end(),[](const auto &x, const auto &b){
    	return x.second < b.second;
    });
    int cnt = 0;
    int cur = 0;
    for(auto [x, y] : v){
    	if(cur <= x){
    		cur = y;
    		cnt++;
    	}
    }

    cout << cnt << '\n';

    return 0;   
}
