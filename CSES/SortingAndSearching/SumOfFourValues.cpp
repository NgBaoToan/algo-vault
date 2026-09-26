 #include <bits/stdc++.h>
 using namespace std;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	cin.tie(0); cout.tie(0);
 	
 	int n, x; cin >> n >> x;
 	vector<pair<int, int>> a;
 	for(int i = 0; i < n; i++){
 		int X; cin >> X;
 		a.push_back({X, i + 1});
 	}

 	sort(a.begin(), a.end());

 	for(int i = 0; i < n - 3; i++){
 		for(int j = i + 1; j < n - 2; j++){
 			int l = j + 1;
 			int r = n - 1;

 			while(l < r){
 				long long sum = a[i].first + a[j].first + a[l].first + a[r].first;
 				if(sum == x){
 					cout << a[i].second << ' '
 					<< a[j].second << ' '
 					<< a[l].second << ' '
 					<< a[r].second << '\n';
 					return 0;
 				}else if(sum > x) r--;
 				else l++;
 			}
 		}
 	}

 	cout << "IMPOSSIBLE\n";
 	return 0;
 }