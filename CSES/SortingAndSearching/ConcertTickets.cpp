#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, q; cin >> n >> q;
    multiset<int> st;
    for(int i = 0; i < n; i++){
    	int x; cin >> x;
    	st.insert(x);
    }

    while(q--){
    	int x; cin >> x;
    	auto it = st.upper_bound(x);

    	if(it != st.begin()){
    		it--;
    		cout << *it << '\n';
   			st.erase(it);
    	}else{
    		cout << -1 << '\n';
    	}
    }
    return 0;   
}
