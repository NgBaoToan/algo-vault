#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		int n, k; cin >> n >> k;
		vector<int> last_pos(1000005, -1);
		
		int found = 0;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			
			if(last_pos[x] != -1 && i - last_pos[x] <= k){
				found = 1;
				break;
			}
			
			last_pos[x] = i;
		}
		
		if(found) cout << "YES\n";
		else cout << "NO\n";
	return 0;
}