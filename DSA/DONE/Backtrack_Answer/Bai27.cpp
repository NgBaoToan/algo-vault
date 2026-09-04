#include <bits/stdc++.h>
using namespace std;

int n;
int pos[20];
int col[20], d1[20], d2[20];

void backtrack(int i){
	if(i > n){
		for(int j = 1; j <= n; j++) cout << pos[j] << ' ';
		cout << '\n';
		return;
	}
	
	for(int j = 1; j <= n; j++){
		if(!col[j] && !d1[i - j + n] && !d2[i + j]){
			pos[i] = j;
			col[j] = d1[i - j + n] = d2[i + j] = 1;
			backtrack(i + 1);
			col[j] = d1[i - j + n] = d2[i + j] = 0;
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