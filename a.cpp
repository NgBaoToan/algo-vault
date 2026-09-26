#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int i, long long val) {
        while (i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    long long query(int i) {
        long long sum = 0;

        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }

        return sum;
    }

    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    Fenwick bits(x.size());

    for(int i = 0; i < n; i++){
        bits.add(i + 1, x[i]);
    }

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int k, u; cin >> k >> u;
            long long dif = u - x[k - 1];
            bits.add(k, dif);
            x[k - 1] = u;
        }else{
            int a, b; cin >> a >> b;
            cout << bits.rangeQuery(a, b) << '\n';
        }
    }
    return 0;
}