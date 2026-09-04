#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> res;

void backtrack(int i, string cur){
    if(i == s.length()){
        res.push_back(cur);
        return;
    }

    if(isalpha(s[i])){
        backtrack(i + 1, cur + (char)tolower(s[i]));
        backtrack(i + 1, cur + (char) toupper(s[i]));
    }else{
        backtrack(i + 1, cur + s[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    backtrack(0, "");

    for(auto& x : res){
        cout << x << '\n';
    }
    return 0;
}