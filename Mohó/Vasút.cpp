#include <bits/stdc++.h>

using namespace std;

int N, K, a, p;
vector <int> x, ans;

int main() {
    cin >> N >> K;
    ans.push_back(1);
    cin >> a;
    p = 0;

    for(int i = 2; i <= N; ++i) {
        cin >> a;
        if (a >= p + K) { // leszáll az utas, ha legalább K távolságra van
            p = a;
            ans.push_back(i);
        }
    }

    if (ans.back() != N) { // ha ezzel a módszerrel nem az utolsó állomáson száll le az utas, akkor az utolsó leszállást módosítani kell
        ans.back() = N;
    }

    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }

    return 0;
}
