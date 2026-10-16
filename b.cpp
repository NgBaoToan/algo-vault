#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long

int n;
vector<string> name;
vector<double> a;

double minSum(int pos, double x) {
    double cur = 0, sum = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (i == pos)
            cur = x;
        else if (a[i] >= 0)
            cur = a[i];

        sum += cur;
    }

    return sum;
}

double maxSum(int pos, double x) {
    double cur = 100, sum = 0;

    for (int i = 0; i < n; i++) {
        if (i == pos)
            cur = x;
        else if (a[i] >= 0)
            cur = a[i];

        sum += cur;
    }

    return sum;
}

void run() {
    cin >> n;
    cin.ignore();

    name.resize(n);
    a.assign(n, -1);

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        ss >> name[i];

        double x;
        if (ss >> x)
            a[i] = x;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) continue;

        double low = 0, high = 100;

        for (int j = 0; j < i; j++) {
            if (a[j] >= 0)
                high = a[j];
        }

        for (int j = i + 1; j < n; j++) {
            if (a[j] >= 0) {
                low = a[j];
                break;
            }
        }

        cout << fixed << setprecision(2);

        double l = low, r = high;

        for (int k = 0; k < 60; k++) {
            double mid = (l + r) / 2;

            if (maxSum(i, mid) >= 100)
                r = mid;
            else
                l = mid;
        }

        double mn = r;

        l = low;
        r = high;

        for (int k = 0; k < 60; k++) {
            double mid = (l + r) / 2;

            if (minSum(i, mid) <= 100)
                l = mid;
            else
                r = mid;
        }

        double mx = stod(ans)

        cout << name[i] << " "
             << mn << " " << mx << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run();

    return 0;
}