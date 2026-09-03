#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;

string binary(int n, string str){
    if(n == 0){
        if(str == "") return "0";
        return str;
    }

    str += to_string(n % 2);
    return binary(n / 2, str);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    string bi = binary(n, "");
    if(n != 0) reverse(bi.begin(), bi.end());

    cout << bi << '\n';

    return 0;
}