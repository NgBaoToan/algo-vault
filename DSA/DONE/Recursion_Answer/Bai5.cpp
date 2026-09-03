#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n;

ll dq(int i){
	if(i > n) return 1;
	return dq(i + 1) * i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
   	cout << dq(1) << '\n';
    return 0;   
}
