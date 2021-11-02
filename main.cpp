#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, v, minimal=1e8;
    cin >> n;
    // 1 - gold | 2 - silver
    vector <int> g(n);  // g[i] = count of gold [0; i]
    vector <int> s(n);  // s[i] = count of silver [0; i]
    for (int i = 0; i < n && cin >> v; ++i) {
        if (i == 0) { g[0] = 2 - v; s[0] = v - 1; }
        else {
            g[i] = g[i - 1] + 2 - v;
            s[i] = s[i - 1] + v - 1;
        }
    }
    for (int i = 0; i < n; ++i) {  // [0;i]U(i;n-1]
        minimal = min(minimal, min(g[i] + s[n - 1] - s[i], s[i] + g[n - 1] - g[i]));
    } cout << minimal << '\n';
    return 0;
}
