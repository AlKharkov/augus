// n * n
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
    d[0] = 0;
    while (true) {
        int minDist = INF;
        int minV = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && d[i] < minDist) {
                minDist = d[i];
                minV = i;
            }
        } if (minDist == INF) break;
        used[minV] = true;
        for (auto [v, w]: g[minV]) {
            if (d[v] > d[minV] + w) d[v] = d[minV] + w;
        }
    }
    for (int x: d) cout << x << ' '; cout << '\n';
    return 0;
}
