#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> pos(n);
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	pos[x] = i;
    }

    int round = 1;
    for(int i = 1; i < n; i++){
    	if(pos[i] > pos[i + 1]) round++;
    }

    cout << round << '\n';
    return 0;   
}
	