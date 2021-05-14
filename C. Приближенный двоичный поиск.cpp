#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n, k, b;
    cin >> n >> k;
    vector <int> a;
    for (int i = 0; i < n; ++i) {  // считываем сразу так, чтобы не было повторяющихся элементов
        cin >> b;
        if (i != 0) {
            if (a[a.size() - 1] != b) a.push_back(b);
        } else a.push_back(b);
    }
    for (int i = 0; i < k; ++i) {
        int l = -1, r = a.size();  // рассматриваем отрезок от l до r(не включая концы)
        cin >> b;
        while (r - l > 2) {
            int mark = (l + r) / 2;
            if (l != mark - 1 && mark != 0) {  // при l = -1 r = 2 => mark = 0
                if (abs(b - a[mark - 1]) > abs(b - a[mark])) l = mark - 1;
                else r = mark;
            } else {  // if (r != mark + 1)
                if (abs(b - a[mark]) > abs(b - a[mark + 1])) l = mark;
                else r = mark + 1;
            }
        } cout << a[(l + r) / 2] << '\n';
    }
}
