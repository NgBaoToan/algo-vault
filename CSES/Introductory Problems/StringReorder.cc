#include <bits/stdc++.h>
#include <cmath>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s; cin >> s;
    int n = s.length();
    int mx = 0;
    map<char, int> freq;
    for(char c : s){
        freq[c]++;
        mx = max(mx, freq[c]);
    }
 
    if(mx > (n + 1) / 2){
        cout << -1 << '\n';
        return 0;
    }  
 
    string ans = "";
    char last = '\0';
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < 26; j++){
            char c = 'A' + j;
            if(freq[c] == 0 || c == last){
                continue;
            }
 
            freq[c]--;
            
            int max_f = 0;
            for(auto const& [key, val] : freq){
                if(val > max_f){
                    max_f = val;
                }
            }
 
            int remain = n - 1 - i;
 
            if(max_f <= (remain + 1) / 2){
                ans += c;
                last = c;
                break;
            }else{
                freq[c]++;
            }
        }
    }
 
    cout << ans << '\n';
    return 0;
