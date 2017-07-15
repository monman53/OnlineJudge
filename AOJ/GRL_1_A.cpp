// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define EPS         (1e-10)
#define MOD         (1000000007LL)
// #define EQ(a, b)    (abs((a)-(b)) < EPS)
inline bool EQ(double a, double b) {return abs(a-b) < EPS;}
// ciling(x/y) = (x+y-1)/y

// template<class T>
// using P = pair<T, T>;
template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

template<class T>
struct E {
    int to;
    T w;
};

template<class T>
struct G {
    vector<vector<E<T>>> e;
    int n;
    G(int _n) {
        n = _n;
        e.resize(n);
    }
    void add(int i, int j, T w) {
        assert(i >= 0 && i < n && j >= 0 && j < n);
        e[i].push_back({j, w});
    }
};

// dijkstra
// verified AOJ GRL_1_A
template<class T>
vector<T> solveDIJ(G<T> g, int i) {
    int inf = numeric_limits<T>::max();
    vector<T> d(g.n, inf);
    priority_queue<PTI<T>, vector<PTI<T>>, greater<PTI<T>>> pq;
    d[i] = 0;
    pq.push({0, i});
    while(!pq.empty()){
        auto c = pq.top();pq.pop();
        int ci = c.second;
        int cd = c.first;
        if(cd > d[ci]) continue;
        for(auto e : g.e[ci]){
            if(cd + e.w < d[e.to]){
                d[e.to] = cd + e.w;
                pq.push({cd + e.w, e.to});
            }
        }
    }
    return d;
}

int main() {
    int v, e, r;cin >> v >> e >> r;
    G<int> g(v);
    for(int i=0;i<e;i++){
        int s, t, d;cin >> s >> t >> d;
        g.add(s, t, d);
    }
    auto ans = solveDIJ(g, r);
    for(auto a : ans){
        if(a == INT_MAX){
            cout << "INF" << endl;
        }else{
            cout << a << endl;
        }
    }
    return 0;
}
