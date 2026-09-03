#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n, a[101];
int target = 0;
int found = 0;
void backtrack(int idx, int sum){
    if(found) return;

    if(sum == target){
        found = 1;
        return;
    }

    for(int i = idx; i < n; i++){
        if(sum + a[i] <= target){
            backtrack(i + 1, sum + a[i]);
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
    int total_sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total_sum += a[i];
    }

    if(total_sum % 2 == 1){
        cout << 0 << '\n';
    }else{
        target = total_sum / 2;
        sort(a, a + n, greater<int>());

        backtrack(0, 0);

        if(found){
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
    }
    return 0;   
}
