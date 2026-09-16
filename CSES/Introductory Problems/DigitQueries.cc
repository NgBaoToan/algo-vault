#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
 
void run(){
    ll k; cin >> k;
    ll L = 1;
    ll cnt = 9;
    ll st = 1;
 
    while(k > L * cnt){
        k -= L * cnt;
        L++;
        cnt *= 10;
        st *= 10;
    } 
 
    ll target = st + (k - 1) / L;
    string s = to_string(target);
    cout << s[(k - 1) % L] << '\n';
}  
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t; cin >> t;
    while(t-- > 0){
        run();
    }
 
    return 0;
}