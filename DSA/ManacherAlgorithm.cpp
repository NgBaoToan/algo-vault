#include <bits/stdc++.h>
using namespace std;

const int MaxN = 255;

int Cnt[MaxN][26];
int Cnt_Odd[MaxN];
int D_odd[MaxN];
int D_even[MaxN];
char c[MaxN][MaxN];
bool Ok[MaxN];

int N, M;
long long Ans = 0;

inline bool EqualRow(int r1, int r2) {
    if (!Ok[r1] || !Ok[r2]) return false;
    for (int j = 0; j < 26; j++) {
        if (Cnt[r1][j] != Cnt[r2][j]) return false;
    }
    return true;
}

void Calc_D_odd() {
    int l = 1, r = 0; // current rightmost palindrome segment [l..r]
    for (int i = 1; i <= N; i++) {
        if (i > r) D_odd[i] = 0;
        else {
            int mirror = l + (r - i); // = l + r - i
            D_odd[i] = min(r - i, D_odd[mirror]);
        }

        if (Ok[i]) {
            while (i - D_odd[i] - 1 > 0 &&
                   i + D_odd[i] + 1 <= N &&
                   EqualRow(i - D_odd[i] - 1, i + D_odd[i] + 1)) {
                D_odd[i]++;
            }
        } else {
            D_odd[i] = 0;
        }

        // count palindromes centered at i: (Ok[i]?1:0) for radius 0, plus D_odd[i] for larger radii
        Ans += (long long)D_odd[i] + (Ok[i] ? 1 : 0);

        if (i + D_odd[i] > r) {
            r = i + D_odd[i];
            l = i - D_odd[i];
        }
    }
}

void Calc_D_even() {
    int l = 1, r = 0; // current rightmost palindrome segment [l..r]
    for (int i = 1; i < N; i++) {
        int j = i + 1;

        if (j > r) D_even[i] = 0;
        else {
            int mirrorLeftIndex = l + (r - j); // corresponds to mirrored "i"
            D_even[i] = min(r - j + 1, D_even[mirrorLeftIndex]);
        }

        while (i - D_even[i] > 0 &&
               j + D_even[i] <= N &&
               EqualRow(i - D_even[i], j + D_even[i])) {
            D_even[i]++;
        }

        Ans += D_even[i];

        // right boundary is i + D_even[i] (since rightmost row is j + D_even[i] - 1 = i + D_even[i])
        if (i + D_even[i] > r) {
            r = i + D_even[i];
            l = j - D_even[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> (c[i] + 1);
    }

    for (int c1 = 1; c1 <= M; c1++) {
        // reset per left column boundary
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < 26; j++) Cnt[i][j] = 0;
            Cnt_Odd[i] = 0;
            Ok[i] = true;
        }

        for (int c2 = c1; c2 <= M; c2++) {
            int len = c2 - c1 + 1;
            int allowedOdd = (len & 1);

            for (int i = 1; i <= N; i++) {
                int t = c[i][c2] - 'a';
                Cnt[i][t]++;

                if (Cnt[i][t] & 1) Cnt_Odd[i]++;
                else Cnt_Odd[i]--;

                Ok[i] = (Cnt_Odd[i] <= allowedOdd);
            }

            Calc_D_odd();
            Calc_D_even();
        }
    }

    cout << Ans;
    return 0;
}
