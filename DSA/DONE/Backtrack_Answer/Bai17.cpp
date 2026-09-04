#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define arr array

int n;
string s = "";
char br[] = {'(', ')', '[', ']', '{', '}'};
int found = 0;

bool isMatch(char open, char close){
	return (open == '(' && close == ')' ||
			open == '[' && close == ']' ||
			open == '{' && close == '}');
}

void backtrack(int i, string cur, string st){
	if(i == n){
		if(st.empty()){
			cout << cur << '\n';
			found = 1;
		}
		return;
	}
	
	if(st.size() > n - 1) return;
	
	for(char c : br){
		if(c == '(' || c == '[' || c == '{'){
			backtrack(i + 1, cur + c, st + c);
		}else{
			if(!st.empty() && isMatch(st.back(), c)){
				string next_st = st;
				next_st.pop_back();
				backtrack(i + 1, cur + c, next_st);
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	if(n % 2 == 1) cout << "NOT FOUND\n";
	else{
		backtrack(0, "", "");
		if(!found) cout << "NOT FOUND\n";
	}
	return 0;
}
