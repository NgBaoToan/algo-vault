#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e6 + 6;

#define ll long long
#define ld long double
#define ar array
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ft first
#define sd second
#define sz(x) (int)(x).size()

void solve(){
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    int q = 0;
    int qa = 0;
    int qaq = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'Q'){
            qaq += qa;
            q++;
        }else if(s[i] == 'A'){
            qa += q;
        }
    }

    cout << qaq << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
