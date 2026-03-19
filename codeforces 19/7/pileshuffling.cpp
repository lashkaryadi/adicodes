#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long w = 0;
    long long x = 0;
    long long y = 0;
    long long z = 0;

    vector<tuple<long long, long long, long long, long long>> piles(n);

    for (int i = 0; i < n; ++i) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        piles[i] = make_tuple(a, b, c, d);
    }

    for (const auto& p : piles) {
        long long a = get<0>(p);
        long long b = get<1>(p);
        long long c = get<2>(p);
        long long d = get<3>(p);

        if (a > c) {
            x += a - c;
        }
        if (b > d) {
            y += b - d;
        }
    }

    for (const auto& p : piles) {
        long long a = get<0>(p);
        long long b = get<1>(p);
        long long c = get<2>(p);
        long long d = get<3>(p);

        if (b > d) {
            z += min(a, c);
        }
    }
    
    w = x + y + z;

    cout << w << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
