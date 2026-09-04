#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> cur;
int found = 0;

void backtrack(int st, int sum){
    if(cur.size() == k){
        if(sum == n){
            for(int i = 0; i < k; i++){
                cout << cur[i];
                if(i < k - 1) cout << " + ";
            }
            cout << '\n';
            found = 1;
        }
    }

    for(int i = st; i <= 9; i++){
        if(sum + i <= n){
            cur.push_back(i);
            backtrack(i + 1, sum + i);
            cur.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    backtrack(1, 0);
    if(!found) cout << "NOT FOUND\n";

    return 0;
}