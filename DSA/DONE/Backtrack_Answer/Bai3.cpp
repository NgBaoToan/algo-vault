#include <bits/stdc++.h>

using namespace std;

int n, check;
int a[101][101];

void backtrack(int i, int j, string path) {
    if (i == n && j == n) {
        check = 1;
        cout << path << '\n';
        return;
    }

    a[i][j] = 0; // Đánh dấu ô đã đi

    // Ưu tiên theo thứ tự từ điển: D -> L -> R -> U
    if (i + 1 <= n && a[i + 1][j] == 1) backtrack(i + 1, j, path + "D");
    if (j - 1 >= 1 && a[i][j - 1] == 1) backtrack(i, j - 1, path + "L");
    if (j + 1 <= n && a[i][j + 1] == 1) backtrack(i, j + 1, path + "R");
    if (i - 1 >= 1 && a[i - 1][j] == 1) backtrack(i - 1, j, path + "U");

    a[i][j] = 1; // Quay lui: trả lại trạng thái ban đầu
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Comment hoặc xóa bỏ freopen khi nộp lên Online Judge
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    if (cin >> n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }

        // Bắt đầu từ ô (1,1)
        backtrack(1, 1, "");

        if (check == 0) cout << -1 << '\n';
    }
    return 0;
}