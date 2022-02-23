// m * log n
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<vector<pair<int, int>>> g(n);
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].emplace_back(v - 1, w);
        g[v - 1].emplace_back(u - 1, w);
    }
    vector<int> d(n, INF);
    vector<bool> used(n, false);
    set<pair<int, int>> s;
    d[0] = 0;
    for (int i = 0; i < n; ++i) s.insert({d[i], i});
    while (!s.empty() && s.begin()->first != INF) {
        int minV = s.begin()->second;
        s.erase(s.begin());
        used[minV] = true;
        for (auto [v, w]: g[minV]) {
            if (d[v] > d[minV] + w) {
                s.erase({d[v], v});
                d[v] = d[minV] + w;
                s.insert({d[v], v});
            }
        }
    }
    for (int e: d) cout << e << ' ';
    return 0;
}
