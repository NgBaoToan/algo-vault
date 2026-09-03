#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    int A[n];
    for(int &x : A) cin >> x;

    int min_len = n + 1;
    int best_l = -1;
    int best_r = -1;
    int l = 0;
    int sum = 0;
    for(int r = 0; r < n; r++){
        sum += A[r];
        while(sum >= k){
            if(r - l + 1 < min_len){
                min_len = r - l + 1;
                best_l = l;
                best_r = r;
            }
            sum -= A[l];
            l++;
        }
    }

    if(best_l == -1){
        cout << -1 << '\n';
    }else{
        for(int i = best_l; i <= best_r; i++){
            cout << A[i] << ' ';
        }
    }
    return 0;
}