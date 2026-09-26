#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; 
    cin >> s;

    vector<int> freq(256, 0);
    int max_len = 0;
    int left = 0;
    for(int right = 0; right < s.length(); right++){
        freq[s[right]]++;
        while(freq[s[right]] > 1){
            freq[s[left]]--;
            left++;
        }
        max_len = max(max_len, right - left + 1);
    }

    cout << max_len << '\n';
    return 0;
}