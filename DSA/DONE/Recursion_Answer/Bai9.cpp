#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

const ll MOD = 1e9 + 7;

ll binPow(ll a, ll b){
	if(b == 0) return 1; //Điều kiện dừng: a ^0 = 1

	//Tính trước a ^ (b / 2) để không bị tính lại lần 2
	ll res = binPow(a, b / 2);

	//Bình phương kết quả: (a ^ (b / 2)) ^ 2 % MOD
	res = (res * res) % MOD;

	//Nếu b lẻ, nhân thêm một lượng a
	if(b % 2 == 1){
		return (res * (a % MOD)) % MOD;
	}

	return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll a, b; cin >> a >> b;
    cout << binPow(a, b) << '\n';
    return 0;   
}
