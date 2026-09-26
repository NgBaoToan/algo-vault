#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

/*
	Policy Based Data Structure
	ordered_set = set + biet thu hang cua phan tu

	no giong set
		tu sap xep tang dan
		khong cho phan tu trung
		insert, erase, find nhanh
		dung cay can bang ben trong
			insert O(log n)
			erase O(log n)
			find O(log n)
			size
			empty
			begin, end
			lower_bound
			upper_bound
	diem khac
		- find_by_order(k) tra ve iterator toi phan tu dung thu k
		k la 0-based
		=> nghia la biet thu han --> tim gia tri
		- order_of_key(x) tra ve so phan tu < x

	Dung PBDS khi bai co kieu: du lieu thay doi lien tuc va can tho thu hang
	
*/


template<typename T>
using ordered_set = tree<
	T,
	null_type,
	less<T>,
	rb_tree_tag,
	tree_order_statistics_node_update
>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;

	ordered_set<int> st;
	for(int i = 1; i <= n; i++){
		st.insert(i);
	}

	long long pos = 0;
	while(!st.empty()){
		pos = (pos + k) % st.size();

		auto it = st.find_by_order(pos);

		cout << *it << ' ';
		st.erase(it);
	}
	return 0;
}