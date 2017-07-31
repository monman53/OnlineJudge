// header {{{
// #define NDEBUG
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
// Union-Find // {{{
// verified AOJ DSL_1_A
struct UF {
    vector<int> p;  // parent
    vector<int> r;  // rank

    UF(int n) {
        p.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
            r[i] = 1;
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
        if(r[x] < r[y]){
            p[x] = y;
        }else{
            p[y] = x;
            if(r[x] == r[y]){
                r[x]++;
            }
        }
    }
}; // }}}

struct D {
    int s, t;
    double w;
};

int main() {
    int n, m;cin >> n >> m;
    vector<double> x(n), y(n);
    vector<D> e(m);
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    double sum = 0;
    for(int i=0;i<m;i++){
        int s, t;cin >> s >> t;s--;t--;
        double dx = x[t] - x[s];
        double dy = y[t] - y[s];
        double w = sqrt(dx*dx+dy*dy);
        sum += w;
        e[i] = D{s, t, w};
    }
    sort(e.begin(), e.end(), [](D &l, D&r){return r.w < l.w;});
    UF uf(n);
    for(int i=0;i<m;i++){
        int s = e[i].s;
        int t = e[i].t;
        double w = e[i].w;
        if(uf.find(s) != uf.find(t)){
            uf.unite(s, t);
            sum -= w;
        }
    }
    printf("%lf\n", sum);
    return 0;
}
