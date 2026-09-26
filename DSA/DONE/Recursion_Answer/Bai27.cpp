#include <iostream>

using namespace std;

// Hàm đệ quy Binary Search O(logN)
// Biến 'res' dùng để lưu vết vị trí thỏa mãn gần nhất tìm được
int upperBoundDesc(int A[], int left, int right, int X, int res) {
    // Điều kiện dừng: không gian tìm kiếm đã cạn kiệt
    if (left > right) return res;
    
    int mid = left + (right - left) / 2;
    
    if (A[mid] > X) {
        // A[mid] lớn hơn X, lưu lại mid và tìm tiếp ở nửa phải xem còn số nào xa hơn không
        return upperBoundDesc(A, mid + 1, right, X, mid);
    } else {
        // A[mid] <= X, các số thỏa mãn (nếu có) phải nằm ở nửa trái (chứa các số lớn hơn)
        return upperBoundDesc(A, left, mid - 1, X, res);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (cin >> n) {
        int A[1005];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        
        int x;
        cin >> x;
        
        // Gọi hàm với res mặc định khởi tạo là n (nếu không tìm thấy sẽ trả về n)
        cout << upperBoundDesc(A, 0, n - 1, x, n) << '\n';
    }
    
    return 0;
}