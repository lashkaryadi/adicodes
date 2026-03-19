#include <iostream>

void solve() {
    int x, y;
    std::cin >> x >> y;
    if (x == 1 || y == 1) {
        std::cout << "NO\n";
    } else if (x == 2 && y == 2) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
