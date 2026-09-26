#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    multiset<int> st;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        auto it = st.upper_bound(x);
        if(it != st.end()) st.erase(it);
        st.insert(x);
    }

    cout << st.size() << '\n';
    
    return 0;   
}
