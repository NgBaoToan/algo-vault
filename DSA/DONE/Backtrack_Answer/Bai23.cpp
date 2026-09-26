#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> primes;
vector<int> cur;
int found = 0;

bool isPrime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void backtrack(int idx, int sum){
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

    for(int i = idx; i < primes.size(); i++){
        if(sum + primes[i] <= n){
            cur.push_back(primes[i]);
            backtrack(i + 1, sum + primes[i]);
            cur.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 2; i <= n; i++){
        if(isPrime(i)) primes.push_back(i);
    }

    backtrack(0, 0);
    if(!found) cout << "NOT FOUND\n";

    return 0;
}