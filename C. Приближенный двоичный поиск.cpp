#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, k, v;
    cin >> n >> k;
    vector <int> a;
    vector <pair<int, int>> b(k);  // значение, индекс вхождения
    for (int i = 0; i < n; ++i) {
        cin >> v;
        if (i == 0) a.push_back(v);
        else if (a[a.size() - 1] != v) a.push_back(v);
    }
    for (int i = 0; i < k; ++i) {
        cin >> v;
        b[i] = {v, i};
    } sort(b.begin(), b.end());
    vector <int> ans(k, -1);
    long ma = 0;
    for (int mb = 0; mb < k; ++mb) {
        while (ans[b[mb].second] == -1) {
            if ((int) a.size() == ma + 1) ans[b[mb].second] = a[ma];
            else if (abs(b[mb].first - a[ma]) <= abs(b[mb].first - a[ma + 1])) ans[b[mb].second] = a[ma];
            else ++ma;
        }
    }
    for (int i: ans) cout << i << '\n';
}
