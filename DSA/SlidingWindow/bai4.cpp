#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		string s; cin >> s;
		unordered_set<char> distinct_chars(s.begin(), s.end());
		
		int total_distinct = distinct_chars.size();
		
		vector<int> freq(256, 0);
		int current_distinct = 0;
		int min_len = s.length();
		int left = 0;
		for(int right = 0; right < s.length(); right++){
			if(freq[s[right]] == 0){
				current_distinct++;
			}
			freq[s[right]]++;
			while(current_distinct == total_distinct){
				min_len = min(min_len, right - left + 1);
				freq[s[left]]--;
				
				if(freq[s[left]] == 0){
					current_distinct--;
				}
				left++;
			}
		}
		
		cout << min_len << '\n';
	return 0;
}