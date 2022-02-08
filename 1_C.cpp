#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, v, m, rev, left, right, cur, ind = -1;
    cin >> n;
    if (n == 1) return 0;
    vector<int> a(n);
    for (int i = 0; i < n && cin >> v; ++i) a[i] = v;
    sort(a.begin(), a.end());
    for (int i: a) cout << i << ' ';
    cout << '\n';
    for (int i = 1; i < n; ++i) {
        if (ind == -1 || a[i] - a[i - 1] < m) {
            ind = i;
            m = a[i] - a[i - 1];
        }
    } cout << m << ' ';
    cur = m;
    int l = ind - 1, r = ind + 1;
    for (int i = 2; 2 * i < n; ++i) {
        rev = ((l > 0 && r < n) ? a[r] - cur - a[l - 1] : 1000000000);
        left = ((l > 1) ? cur + a[l - 1] - a[l - 2] : 1000000000);
        right = ((r + 1 < n) ? cur + a[r + 1] - a[r] : 1000000000);
        if (rev <= left && rev <= right) {
            --l;
            ++r;
            cur = rev;
        } else if (right <= rev && right <= left) {
            r += 2;
            cur = right;
        } else {
            l -= 2;
            cur = left;
        } cout << cur << ' ';
    } cout << '\n';
    return 0;
}
