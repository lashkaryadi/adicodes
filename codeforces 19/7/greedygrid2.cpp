#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long M = 998244353;

void solve() {
    long long n, k;
    cin >> n >> k;
    vector<vector<long long>> g(2, vector<long long>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    long long dp0 = 0, dp1 = 0, dp2 = 0;

    for (int i = 0; i < n; ++i) {
        long long x = g[0][i];
        long long y = g[1][i];
        long long w0 = 0, w1 = 0, w2 = 0;

        long long k_ll = k;
        long long ways_diff = (k_ll * (k_ll - 1) / 2) % M;

        if (x == -1 && y == -1) {
            w0 = ways_diff;
            w1 = ways_diff;
            w2 = k;
        } else if (x == -1) {
            w0 = k - y;
            w1 = y - 1;
            w2 = 1;
        } else if (y == -1) {
            w0 = x - 1;
            w1 = k - x;
            w2 = 1;
        } else {
            if (x > y) w0 = 1;
            if (y > x) w1 = 1;
            if (x == y) w2 = 1;
        }

        if (i == 0) {
            dp0 = w0;
            dp1 = w1;
            dp2 = w2;
        } else {
            long long p_sum = (dp0 + dp1 + dp2) % M;
            long long p0 = dp0;
            long long p1 = dp1;

            long long next_dp0 = ((p_sum - p0 + M) % M * w0) % M;
            long long next_dp1 = ((p_sum - p1 + M) % M * w1) % M;
            long long next_dp2 = (p_sum * w2) % M;
            
            dp0 = next_dp0;
            dp1 = next_dp1;
            dp2 = next_dp2;
        }
    }

    long long z = (dp0 + dp1 + dp2) % M;
    cout << z << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
