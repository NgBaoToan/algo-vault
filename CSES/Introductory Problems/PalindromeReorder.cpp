#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
 
     vector<int> cnt(26, 0);
     for(char c : s){
        cnt[c - 'A']++;
     }
 
     int odd_count = 0;
     int idx = -1;
     for(int i = 0; i < 26; i++){
        if(cnt[i] % 2 != 0){
            odd_count++;
            idx = i;
        }
     }
 
     if(odd_count > 1){
        cout << "NO SOLUTION\n";
        return 0;
     }
 
    string left = "";
    for(int i = 0; i < 26; i++){
        left += string(cnt[i] / 2, i + 'A');
    }
 
    string right = left;
    reverse(right.begin(), right.end());
    string mid = "";
    if(idx != -1){
        mid = string(1, idx + 'A');
    }
 
    cout << left + mid + right << '\n';
    return 0;
}