#include <iostream>

using namespace std;

// Tham số res dùng để lưu lại vị trí tốt nhất tạm thời
int lowerBoundAsc(int A[], int left, int right, int k, int res) {
    // Điều kiện dừng
    if (left > right) return res;
    
    int mid = left + (right - left) / 2;
    
    if (A[mid] >= k) {
        // Nếu A[mid] >= k, đây có thể là đáp án. 
        // Lưu lại mid vào res và tiếp tục ép không gian tìm kiếm sang nửa TRÁI 
        // để tìm xem có vị trí nào xuất hiện sớm hơn không.
        return lowerBoundAsc(A, left, mid - 1, k, mid);
    } else {
        // Nếu A[mid] < k, số cần tìm chắc chắn nằm ở nửa PHẢI.
        return lowerBoundAsc(A, mid + 1, right, k, res);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; 
    if (cin >> n) {
        int A[1005];
        for(int i = 0; i < n; i++) cin >> A[i];
        
        int k; 
        cin >> k;
        
        // Khởi tạo res = -1 để khớp với logic trả về -1 khi không tìm thấy của bạn
        cout << lowerBoundAsc(A, 0, n - 1, k, -1) << '\n';
    }
    
    return 0;
}