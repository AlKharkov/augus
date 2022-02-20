// Считает сумму на элементов от l до r
// https://codeforces.com/group/vFSmSXOI5Y/contest/363406/problem/A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> a;
vector<long long> t;

void build(long long v, long long l, long long r) {
    if (l + 1 == r) {
        t[v] = a[l];
        return;
    } long long mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid, r);
    t[v] = t[2 * v] + t[2 * v + 1];
}

void upd(long long v, long long l, long long r, long long pos, long long x) {
    if (l + 1 == r) {
        t[v] = x;
        return;
    } long long mid = (l + r) / 2;
    if (pos < mid) upd(2 * v, l, mid, pos, x);
    else upd(2 * v + 1, mid, r, pos, x);
    t[v] = t[2 * v] + t[2 * v + 1];
}

long long get(long long v, long long l, long long r, long long ql, long long qr) {
    if (r <= ql || l >= qr) return 0;
    if (ql <= l && r <= qr) return t[v];
    long long mid = (l + r) / 2;
    return get(2 * v, l, mid, ql, qr) + get(2 * v + 1, mid, r, ql, qr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, k, l, r;
    char c;
    cin >> n >> k;
    a = vector<long long> (n, 0);
    t = vector<long long> (4 * n);
    // for (int i = 0; i < n && cin >> v; ++i) a[i] = v;
    // build(1, 0, n);
    for (int i = 0; i < k && cin >> c >> l >> r; ++i) {
        if (c == 'A') upd(1, 0, n, l - 1, r);
        else cout << get(1, 0, n, l - 1, r) << '\n';
    } return 0;
}