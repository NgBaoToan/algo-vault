#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

vector<string> boards(8);
int ways = 0;

int col[9], d1[15], d2[15];

void backtrack(int r){
	if(r == 8){
		ways++;
		return;
	}

	for(int c = 0; c < 8; c++){
		if(boards[r][c] == '.' && !col[c] && !d1[r - c + 7] && !d2[r + c]){
			col[c] = d1[r - c  + 7] = d2[r + c] = 1;
			backtrack(r + 1);
			col[c] = d1[r - c  + 7] = d2[r + c] = 0;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 8; i++){
    	cin >> boards[i];
    }

    backtrack(0);
    cout << ways << '\n';
    return 0;   
}
