#include <bits/stdc++.h>

using namespace std;

int n, k;
int A[101];
vector<vector<int>> res;

void backtrack(int st, int sum, vector<int>& path){
    if(sum == k){
        res.push_back(path);
        return;
    }

    for(int i = st; i < n; i++){
        if(sum + A[i] <= k){
            path.push_back(A[i]);
            backtrack(i + 1, sum + A[i], path);
            path.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Xóa/comment freopen khi nộp bài
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    if (cin >> n >> k) {
        // Sửa vòng lặp nhập dữ liệu theo đúng n
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        
        sort(A, A + n);
        vector<int> path;
        backtrack(0, 0, path);

        if(res.empty()){
            cout << -1 << '\n';
        } else {
            for(auto &a : res){
                // In định dạng đúng yêu cầu bài toán
                cout << "[";
                for(int i = 0; i < a.size(); i++){
                    cout << a[i] << (i == a.size() - 1 ? "" : " ");
                }
                cout << "]\n";
            }
        }
    }
    return 0;   
}