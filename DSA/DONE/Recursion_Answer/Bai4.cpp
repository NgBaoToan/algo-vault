#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n;

ll dq(int i, ll sum){
	if(i > n) return sum;
	if(i % 2 == 0) return i + dq(i + 1);
	else return -i + dq(i + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    cin >> n;
    cout << dq(1, 0LL) << '\n';
    return 0;   
}
