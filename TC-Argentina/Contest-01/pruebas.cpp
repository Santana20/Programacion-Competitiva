#include <bits/stdc++.h>
 
using namespace std;
 
int c = 0, mini = 1e9, prevv = 1e9;
bool found = false, breakdis = false;
 
void rec(int n, int m, int a) {
    if (n >= m) {
        prevv = mini;
        mini = min(c + (n - m), mini);
        if (mini < c + (n - m)) breakdis = true;
        return;
    }

    int aux, res;

    for (int i = n; i > a; i--) {
        aux = i, res = 0;

        while (aux < m) aux *= 2, res++;
        while (aux > i) {
            c += n - i + res;
            rec(aux, m, aux / 2);
            c -= n - i + res;

            if (found) return;

            if (breakdis) {
                breakdis = false;
                break;
            }

            aux /= 2, res--;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    if (n > m) cout << n - m;
    else {
        rec(n, m, 0);
        cout << mini;
    }

    return 0;
}