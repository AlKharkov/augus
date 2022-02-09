#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, add;
    cin >> n >> m;
    char c;
    vector<vector<bool>> a(n, vector<bool> (m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m && cin >> c; ++j) a[i][j] = (c == '#');
    long long ans = 0;
    bool correct;
    // for matrix with 2x2 center
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
                ++ans;
                correct = true;
                add = 1;
                while (correct && (i - add >= 0) && (i + add + 1 < n) && (j - add >= 0) && (j + add + 1) < m) {
                    // for vertical
                    for (int q = i - add + 1; (q < i + add + 1) && correct; ++q) if (a[q][j - add]) correct = false;
                    for (int q = i - add + 1; (q < i + add + 1) && correct; ++q) if (a[q][j + add + 1]) correct = false;
                    // for horizontal
                    for (int w = j - add + 1; (w < j + add + 1) && correct; ++w) if (a[i - add][w]) correct = false;
                    for (int w = j - add + 1; (w < j + add + 1) && correct; ++w) if (a[i + add + 1][w]) correct = false;
                    // for angles
                    if (!a[i - add][j - add] || !a[i - add][j + add + 1] || !a[i + add + 1][j - add] || !a[i + add + 1][j + add + 1]) correct = false;
                    if (correct) {
                        ++add;
                        ++ans;
                    }
                }
            }
        }
    }
    // for matrix with 3x3 center
    for (int i = 0; i + 2 < n; ++i) {
        for (int j = 0; j + 2 < m; ++j) {
            if (a[i][j] && a[i + 1][j + 1] && a[i + 2][j + 2] && a[i + 2][j] && a[i][j + 2] && !a[i + 1][j] && !a[i + 1][j + 2] && !a[i][j + 1] && !a[i + 2][j + 1]) {
                ++ans;
                correct = true;
                add = 1;
                while (correct && (i - add >= 0) && (i + add + 2 < n) && (j - add >= 0) && (j + add + 2) < m) {
                    // for vertical
                    for (int q = i - add + 2; (q < i + add + 2) && correct; ++q) if (a[q][j - add]) correct = false;
                    for (int q = i - add + 2; (q < i + add + 2) && correct; ++q) if (a[q][j + add + 2]) correct = false;
                    // for horizontal
                    for (int w = j - add + 2; (w < j + add + 2) && correct; ++w) if (a[i - add][w]) correct = false;
                    for (int w = j - add + 2; (w < j + add + 2) && correct; ++w) if (a[i + add + 2][w]) correct = false;
                    // for angles
                    if (!a[i - add][j - add] || !a[i - add][j + add + 2] || !a[i + add + 2][j - add] || !a[i + add + 2][j + add + 2]) correct = false;
                    if (correct) {
                        ++add;
                        ++ans;
                    }
                }
            }
        }
    } cout << ans << '\n';
    return 0;
}
