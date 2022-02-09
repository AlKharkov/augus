#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, v, w = 0, m = -1;
    cin >> n;
    set<int> a;
    map<int, int> b;
    for (int i = 0; i < n && cin >> v; ++i) {
        if (a.insert(v).second) b[v] = 1;
        else ++b[v];
    }
    // max value of b
    for (auto & it : b) {
        if (it.second > m) {
            m = it.second;
            v = it.first;
            w = 1;
        } else if (it.second == m) ++w;
    }
    if (2 * m > n || (n % 2 == 1 && 2 * m >= n + 1 && w > 1)) {
        cout << "-1\n";
        return 0;
    }
    return 0;
}