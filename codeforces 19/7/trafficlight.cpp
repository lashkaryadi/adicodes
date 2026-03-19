#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using ll = long long;

struct s {
    ll t;
    int e;
    int u;

    bool operator>(const s& other) const {
        if (t != other.t) {
            return t > other.t;
        }
        return e < other.e;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::vector<std::pair<ll, int>> d(n + 1, {std::numeric_limits<ll>::max(), 0});
    std::priority_queue<s, std::vector<s>, std::greater<s>> q;

    d[1] = {0, 0};
    q.push({0, 0, 1});

    while (!q.empty()) {
        s c = q.top();
        q.pop();

        ll t = c.t;
        int e = c.e;
        int x = c.u;

        if (t > d[x].first || (t == d[x].first && e < d[x].second)) {
            continue;
        }

        if (x == n) {
            break;
        }

        ll deg = g[x].size();
        if (deg == 0) {
            continue;
        }

        for (int i = 0; i < deg; ++i) {
            int y = g[x][i];
            
            ll rem = t % deg;
            ll w = (i - rem + deg) % deg;
            
            ll nt = t + w + 1;
            int ne = e + 1;

            if (nt < d[y].first || (nt == d[y].first && ne > d[y].second)) {
                d[y] = {nt, ne};
                q.push({nt, ne, y});
            }
        }
    }

    ll total_t = d[n].first;
    ll total_e = d[n].second;
    ll wait_t = total_t - total_e;

    std::cout << total_t << " " << wait_t << std::endl;
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