#include <algorithm>
#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

struct Range{
	long long x, y;
	int idx;
};

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

	int n; cin >> n;
	vector<Range> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].x >> a[i].y;
		a[i].idx = i;
 	}

 	sort(a.begin(), a.end(), [](const auto &A, const auto &B){
 		if(A.x == B.x) return A.y > B.y;
 		return A.x < B.x;
 	});

 	vector<int> ys;
 	for(auto r : a){
 		ys.push_back(r.y);
 	}

 	sort(ys.begin(), ys.end());
 	ys.erase(unique(ys.begin(), ys.end()), ys.end());

 	auto getPos = [&](int y){
 		return lower_bound(
 			ys.begin(),
 			ys.end(),
 			y
 			) - ys.begin() + 1;
 	};

 	vector<int> contains(n);
 	vector<int> contained(n);

 	Fenwick bit1(ys.size());

 	for(int i = n - 1; i >= 0; i--){
 		int pos = getPos(a[i].y);
 		contains[a[i].idx] = bit1.query(pos);
 		bit1.add(pos, 1);
 	}

 	Fenwick bit2(ys.size());

 	for(int i = 0; i < n; i++){
 		int pos = getPos(a[i].y);

 		contained[a[i].idx] = i - bit2.query(pos - 1);
 		bit2.add(pos, 1);
 	}

 	for(auto &x : contains){
 		cout << x << ' ';
 	}

 	cout << '\n';
 	for(auto &x : contained){
 		cout << x << ' ';
 	}
	return 0;
}