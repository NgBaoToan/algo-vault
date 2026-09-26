#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n, x;
int A[10001];
 vector<vector<int>> res;

 void backtrack(int idx, int sum, vector<int>& path){
    if(sum == x){
        res.push_back(path);
        return;
    }

    for(int i = idx; i < n; i++){
        if(sum + A[i] <= x){
            path.push_back(A[i]);
            backtrack(i, sum + A[i], path);
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

    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> A[i];

    sort(A, A + n);

    vector<int> path;

    backtrack(0, 0, path);

    if(res.empty()){
        cout << -1 << '\n';
    }else{
        cout << res.size() << '\n';
        for(auto &x : res){
            cout << "{";
            for(int i = 0; i < x.size(); i++){
                cout << x[i];
                if(i < n - 1) cout << ' ';
            }
            cout << "}";
        }
    }
    return 0;   
}
