// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}
// Union-Find (short) {{{
struct UF_short {
    vector<int> p;  // parent

    UF_short(int n) {
        p.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }

    int find(int x) {
        if(x == p[x]){
            return x;
        }else{
            return p[x] = find(p[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        p[y] = p[x];
    }
}; // }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, w, h;cin >> n >> w >> h;
    vector<int> X(w+1, -1);
    vector<int> Y(h+1, -1);
    UF_short uf(n);
    int wall = 0;
    for(int i=0;i<n;i++){
        int x, y;cin >> x >> y;
        if(x == 1 || x == w || y == 1 || y == h){
            wall=1;
        }
        if(X[x] < 0){
            X[x] = i;
        }else{
            uf.unite(i, X[x]);
        }
        if(Y[y] < 0){
            Y[y] = i;
        }else{
            uf.unite(i, Y[y]);
        }
    }
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(uf.find(i));
    }
    int count = s.size();
    if(count == 1){
        cout << n-1 << endl;
    }else{
        cout << n-count + 2*count-1 - wall << endl;
    }
    return 0;
}
