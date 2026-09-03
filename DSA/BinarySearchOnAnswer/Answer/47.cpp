#include <bits/stdc++.h>
using namespace std;
/*
    Nếu trong x giây có thể làm ra t sản phẩm, thì chắc chắn trong X + 1, X + 2,... giây cũng sẽ làm ít nhất t sản phẩm
    Ngược lại, nếu X giây không đủ để làm ra t sản phẩm, thì mọ mức thời gian nhỏ hơn X cũng chắc chắn không đủ
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        long long n, t; cin >> n >> t;
        vector<long long> k(n);

        for(long long &x : k) cin >> x;
        long long l = *min_element(k.begin(), k.end());
        long long r = l * t;
        long long ans = r;

        while(l <= r){
            long long mid = l + (r - l) / 2;
            long long products = 0;
            for(int i = 0; i < n; i++){
                products += (mid / k[i]);
                if(products >= t){
                    break;
                }
            }
            if(products >= t){
                ans = mid;
                r = mid - 1; //thu tim thoi gian ngan hon
            }else{
                l = mid + 1; //khong du san pham, buoc phai tang thoi gian
            }
        }

        cout << ans << '\n';
    return 0;
}
