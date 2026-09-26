#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n + 1), pos(n + 2);
    pos[n + 1] = n + 1;
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	a[i] = x;
    	pos[x] = i;
    }

    int round = 1;

    for(int i = 1; i < n; i++){
    	if(pos[i] > pos[i + 1]) round++;
    }

    for(int i = 0; i < m; i++){
    	int l, r; cin >> l >> r;
    	int x = a[l];
    	int y = a[r];

    	set<pair<int,int>> st;
    	if(x > 1) st.insert({x - 1, x});
    	if(x < n) st.insert({x, x + 1});
    	if(y > 1) st.insert({y - 1, y});
    	if(y < n) st.insert({y, y + 1});

    	for(auto &s : st){
    		if(pos[s.first] > pos[s.second]) round--;
    	}

    	swap(a[l], a[r]);
    	pos[x] = r;
    	pos[y] = l;
    	for(auto p : st){
    		if(pos[p.first] > pos[p.second]) round++;
    	}

    	cout << round << '\n';
    }


    return 0;   
}
