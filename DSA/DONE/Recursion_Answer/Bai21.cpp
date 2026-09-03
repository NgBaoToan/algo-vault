#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

bool isSymmetric(vector<int> a, int l, int r){
    if(l >= r) return true;

    if(a[l] != a[r]) return false;
    
    return isSymmetric(a, l + 1, r - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(isSymmetric(a, 0, n - 1)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}