#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    if(s.length() == 1) {
    	cout << 1 << '\n';
    	return 0;
	}
    int cnt = 1;
    int mx = -1e9;
    for(int i = 1; i < s.length(); i++){
    	if(s[i] == s[i - 1]) cnt++;
    	else{
    		cnt = 1;
		}
		mx = max(cnt, mx);
	}
	
	cout << mx << '\n';
    return 0;
}