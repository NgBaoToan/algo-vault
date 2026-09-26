#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, n; cin >> x >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    set<int> st;
    multiset<int> len;
    st.insert(0);
    st.insert(x);

    len.insert(x);

    for(int i = 0; i < n; i++){
        auto it = st.upper_bound(p[i]);

        int r = *it;
        --it;

        int l = *it;

        len.erase(len.find(r - l));
        len.insert(p[i] - l);
        len.insert(r - p[i]);
        st.insert(p[i]);

        cout << *len.rbegin() << ' ';
    }

    return 0;   
}
