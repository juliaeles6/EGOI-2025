#include <bits/stdc++.h>

using namespace std;

struct Person{
    int start, end;
};

Person x[1001];
int s[301], N, M;
vector<int> ans;

int searchMax(int t) {
    int k = 0;
    for(int i = 1; i <= N; ++i) {
        if(x[i].start <= t && t <= x[i].end && x[i].end > x[k].end) {
            k = i;
        }
    }

    ans.push_back(k); // őt kiválasztjuk
    return k;
}

int searchNext(int e){
    for(int i = 1; i <= M; ++i) {
        if(s[i] > e) {
            return i;
        }
    }

    return 0;
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) {
        cin >> x[i].start >> x[i].end;
    }

    for(int j = 1; j <= M; ++j) {
        cin >> s[j];
    }

    int i = 1, j = 0;

    while(i != 0) {
        j = searchMax(s[i]); // megkeressük az i-dik eseményhez tartozó olyan embert, aki látta és a legtovább ott maradt
        if(j == 0) { // ha nincs ilyen, akkor 0-t kell kiírni
            cout << 0 << '\n';
            return 0;
        }

        i = searchNext(x[j].end); // megkeresssük az következő lefedetlen eseményt
    }

    cout << ans.size() << '\n';
    for(auto e : ans)
        cout << e << ' ';
    return 0;
}