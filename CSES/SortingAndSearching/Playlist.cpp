#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    int cnt = 0;
    int mxLen = 0;
    map<int, int> pos;

    for(int i = 0; i < n; i++){
    	int song = a[i];
    	if(pos.count(song) && pos[song] >= cnt){
    		cnt = pos[song] + 1;
    	}
    	pos[song] = i;
    	mxLen = max(i - cnt + 1, mxLen);
    }

    cout << mxLen << '\n';
    return 0;   
}
