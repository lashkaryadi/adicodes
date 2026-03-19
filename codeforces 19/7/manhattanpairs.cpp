#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
    int id;
};

long long calculate_total_distance(const vector<Point>& p) {
    long long z = 0;
    int n = p.size();
    for (int i = 0; i < n / 2; ++i) {
        long long x1 = p[i].x;
        long long y1 = p[i].y;
        long long x2 = p[n - 1 - i].x;
        long long y2 = p[n - 1 - i].y;
        z += abs(x1 - x2) + abs(y1 - y2);
    }
    return z;
}

void solve() {
    int n;
    cin >> n;

    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i + 1;
    }

    vector<Point> x_sorted = p;
    vector<Point> y_sorted = p;

    sort(x_sorted.begin(), x_sorted.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    sort(y_sorted.begin(), y_sorted.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });

    long long z1 = calculate_total_distance(x_sorted);
    long long z2 = calculate_total_distance(y_sorted);

    if (z1 >= z2) {
        for (int i = 0; i < n / 2; ++i) {
            cout << x_sorted[i].id << " " << x_sorted[n - 1 - i].id << "\n";
        }
    } else {
        for (int i = 0; i < n / 2; ++i) {
            cout << y_sorted[i].id << " " << y_sorted[n - 1 - i].id << "\n";
        }
    }
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
