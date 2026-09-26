#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

string key[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string s;
string cur = "";

void backtrack(int idx){
    if(idx == s.length()){
        cout << cur << '\n';
        return;
    }

    int d = s[idx] - '0';
    for(char c : key[d]){
        cur += c;
        backtrack(idx + 1);
        cur.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> s;
    backtrack(0);
    return 0;   
}
