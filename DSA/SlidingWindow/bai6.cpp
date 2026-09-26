#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		string s, t;
		cin >> s >> t;
		int S = s.length(), T = t.length();
		
		if(S < T){
			cout << -1 << '\n';
			return 0;
		}

		vector<int> freq_t(256, 0);
		for(char c : t){
			freq_t[c]++;
		}
		vector<int> freq_s(256, 0);
		int cnt = 0;
		int l = 0;
		int min_len = 1e9 + 7;
		int st = -1;

		for(int r = 0; r < S; r++){
			char cur = s[r];
			if(freq_s[cur] < freq_t[cur]){
				cnt++;
			}
			freq_s[cur]++;

			while(cnt == T){
				if(r - l + 1 < min_len){
					min_len = r - l + 1;
					st = l;
				}

				char l_char = s[l];
				freq_s[l_char]--;
				if(freq_s[l_char] < freq_t[l_char]){
					cnt--;
				}
				l++;
			}
		}

		if(st == -1){
			cout << -1 << '\n';
		}else{
			cout << s.substr(st, min_len) << '\n';
		}
	return 0;
}