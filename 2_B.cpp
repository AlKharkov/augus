#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, v;
    cin >> n >> k;
    if (n == 1) {  // в ограничениях есть, хотя 1 <= k <= [n/2] => странно
        cout << "0\n";
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n && cin >> v; ++i) a[i] = v;  // считали данные
    multiset<int> b;  // сначала храним тут k суффиксных минимумов
    vector<long long> c(n, 0);  // суммы суффиксных минимумов
    c[n - 1] = a[n - 1];  // т.к. ответ пересчитываем через c[i + 1]
    b.insert(a[n - 1]);
    for (int i = n - 2; i > 0; --i) {
        if (b.size() < k) {  // нужно ли выкидывать элемент, прежде, чем добавить новый?
            b.insert(a[i]);
            c[i] = c[i + 1] + a[i];
        } else if (a[i] < *b.rbegin()) {  // если появился минимум, который меньше наибольшего
            c[i] = c[i + 1] + a[i] - *b.begin();
            b.erase(*(--b.end()));  // выкидываем максимальный минимум
            b.insert(a[i]);
        } else c[i] = c[i + 1];  // если минимумы такие же, то их сумма прежняя
    } b.clear();  // теперь храним тут k префиксных максимумов
    long long ans, sum = 0;
    for (int i = 0; i < k; ++i) {  // считаем сами максимумы их их суммы
        sum += a[i];
        b.insert(a[i]);
    } ans = sum - c[k];  // префикс [0; k) и суффикс [k; n)
    for (int i = k; i + k < n; ++i) {  // теперь на все элементы не хватает места
        if (a[i] > *b.begin()) {  // появился ли новый масимум
            sum += a[i] - *b.begin();
            b.erase(b.begin());
            b.insert(a[i]);
        } ans = max(ans, sum - c[i + 1]);  // может префикс [0; i] и суффикс [i; n) лучше подойдут
    } cout << ans << '\n';
    return 0;  // Вывод: комментирование кода не спасает от проблем :(
}
