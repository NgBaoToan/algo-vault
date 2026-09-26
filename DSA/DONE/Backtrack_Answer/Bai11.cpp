#include <bits/stdc++.h>
#include <string>

using namespace std;

#define ll long long
#define arr array

int n, a[101];
vector<string> res;

void backtrack(int idx, vector<int>& path){
    if(path.size() >= 2){
        string s = "";
        for(int i = 0; i < path.size(); i++){
            s += to_string(path[i]) + (i == path.size() - 1 ? "" : " ");
        }
        res.push_back(s);
    }

    for(int i = idx; i < n; i++){
        if(path.empty() || a[i] > path.back()){
            path.push_back(a[i]);
            backtrack(i + 1, path);
            path.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    for(int &x : a) cin >> x;

    vector<int> path;
    backtrack(0, path);
    sort(res.begin(), res.end());

    for(const string& s: res){
        cout << s << '\n';
    }
    return 0;   
}
