#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
    	long long y, x; cin >> y >> x;
    	long long z = max(x, y);
    	if(z % 2 == 0){
    		if(y == z){
    			cout << z * z - x + 1 << '\n';
			}else{
				cout << (z - 1) * (z - 1) + y << '\n';
			}
		}else{
			if(y == z){
				cout << (z - 1) * (z - 1) + x << '\n';
			}else{
				cout << z * z - y + 1 << '\n';
			}
		}
	}
    return 0;
}
