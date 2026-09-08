#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    sort(s.begin(), s.end());
    vector<string> res;
    do{
    	res.push_back(s);
	}while(next_permutation(s.begin(), s.end()));

	cout << res.size() << '\n';
	for(string x : res){
		cout << x << '\n';
	}
    return 0;
}
