#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    if(n == 1){
    	cout << 1 << '\n';
    	return 0;
	}
    
    if(n <= 3){
    	cout << "NO SOLUTION\n";
    	return 0;
	}
    
    for(int i = 2; i <= n; i++){
    	if(i % 2 == 0){
    		cout << i << ' ';
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(i & 1) cout << i << ' ';
	}
    return 0;
}
