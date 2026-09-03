#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n;

double dq(int a, double sum){
	if(a > n) return sum;
	return dq(a + 1, 1.0 / a + sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

   	cin >> n;

    cout << fixed << setprecision(3) << dq(1, 0.0) << '\n';
    return 0;   
}
