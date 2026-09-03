#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> bit;
int max_val;

void update(int idx, int delta){
    for(; idx <= max_val; idx += idx & -idx){
        bit[idx] += delta;
    }
}

void find_kth(int target){
    int idx = 0;
    for(int step = 1 << 18; step > 0; step >>= 1){
        if(idx + step <= max_val && bit[idx + step] < target_k){
            idx += step;
            target_k -= bit[idx];
        }
        return idx + 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);




    return 0;
}