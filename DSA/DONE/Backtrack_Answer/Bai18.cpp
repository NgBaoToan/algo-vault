#include <bits/stdc++.h>
using namespace std;

int n;
int col[20], d1[40], d2[40], pos[20];

void backtrack(int i){
	if(i > n){
		for(int r = 1; r <= n; r++){
			for(int c = 1; c <= n; c++){
				if(pos[r] == c) cout <<"Q";
				else cout << ".";
			}
			cout << '\n';
		}
		cout << '\n';
		return;
	}

	for(int j = 1; j <= n; j++){
		if(!col[j] && !d1[i - j + n] && !d2[i + j - 1]){
			pos[i] = j;
			col[j] = d1[i - j + n] = d2[i + j - 1] = 1;
			backtrack(i + 1);
			col[j] = d1[i - j + n] = d2[i + j - 1] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	backtrack(1);

	return 0;
}