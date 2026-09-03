#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;


ll dq1(int i, ll sum) {
    if(i > n) return sum;
    return dq1(i + 1, sum + i);
}

ll dq2(int i){
	if(i > n) return 0;
	return i + dq2(i + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    cout << dq1(1, 0LL) << '\n' << dq2(1);
    return 0;   
}