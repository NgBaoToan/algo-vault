#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n; 
    cin >> n;
    long long total = n * (n + 1) / 2;
    
    if(total & 1){
        cout << "NO\n";
        return 0;
    } else {
        cout << "YES\n";
        total /= 2;
        vector<int> a, b;
        for(long long i = n; i >= 1; i--){
            if(total - i >= 0){
                total -= i;
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }
        
        cout << a.size() << '\n';
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
        cout << b.size() << '\n';
        for(int i = 0; i < b.size(); i++){
            cout << b[i] << ' ';
        }
    }
    return 0;
}