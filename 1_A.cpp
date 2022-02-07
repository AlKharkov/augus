#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, v;
    long long k, sum, ans=0;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int> (m));
    vector<vector<int>> b(n, vector<int> (m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m && cin >> v; ++j) a[i][j] = v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) b[0][0] = a[0][0];
            else if (i == 0) b[0][j] = b[0][j - 1] + a[i][j];
            else if (j == 0) b[i][0] = b[i - 1][0] + a[i][j];
            else b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
        }
    }
    return 0;
}
