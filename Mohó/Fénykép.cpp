#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int> > x;
vector <int> ans;
int N, a, b, c, d;

void calc_intersection(int i, int a, int b) {
    // nincs közös rész
    if (a > x[i].second || b < x[i].first) {
        c = 0;
        d = 0;
    }
    else {
        c = max(a, x[i].first);
        d = min(b, x[i].second);
    }
}

int main() {
    cin >> N;
    x.resize(N + 1, { 0,0 });
    for (int i = 1; i <= N; ++i) {
        cin >> x[i].first >> x[i].second;
        --x[i].second; // A távozás időpillanatában készült képen már nincs rajta a szöveg szerint
    }

    sort(x.begin(), x.end()); // Rendezzük érkezés időpontja szerint
 
    // [a, b] jelöli azt az intervallumot, amin belül kell képet csinálni
    a = x[1].first;
    b = x[1].second;
    int i = 2;
    while (i <= N) {
        calc_intersection(i, a, b); // kiszámolom az aktuális vendéggel a metszetet [c, d] intervallumba
        while (c != 0 && i <= N) { // ezt addig csinálom, amíg nem lesz üres a metszet
            a = c;
            b = d;
            ++i;
            calc_intersection(i, a, b);
        }

        ans.push_back(a); // az utolsó megmaradt intervallum elejére teszem a fénykép időpontját
        a = x[i].first;
        b = x[i].second;
    }

    cout << ans.size() << '\n';
    for (auto e : ans)
        cout << e << ' ';
    return 0;
}
