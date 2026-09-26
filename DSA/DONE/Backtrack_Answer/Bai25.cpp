#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> cur;

bool isPalindrome(const string& str){
    int l = 0, r = str.length() - 1;
    while(l < r){
        if(str[l] != str[r]) return false;
        l++; r--;
    }
    return true;
}

void backtrack(int st){
    if(st == s.length()){
        for(const string& x : cur) cout << x << ' ';
        cout << '\n';
        return;
    }

    for(int i = st; i < s.length(); i++){
        string sub = s.substr(st, i - st + 1);
        if(isPalindrome(sub)){
            cur.push_back(sub);
            backtrack(i + 1);
            cur.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    backtrack(0);

    return 0;
}