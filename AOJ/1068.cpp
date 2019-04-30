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
// Segment tree (2D) {{{
// AOJ 1068
template<class T>
struct SGT2 {
    vector<T> dat;
    int h, w;
    T init;
    SGT2(){}
    SGT2(int h, int w, T init) {
        this->init = init;
        this->h = h;
        this->w = w;
        dat = vector<T>(h*w*8, init);
    }

    T update(int i, int j, T x, int k, int si, int sj, int ti, int tj) {
        if(i < si || ti <= i || j < sj || tj <= j) return dat[k];
        int di = ti-si;
        int dj = tj-sj;
        int ci = (si+ti)/2;
        int cj = (sj+tj)/2;
        if(di == 1 && dj == 1) return dat[k] = x;
        if(di < dj){
            T v0 = update(i, j, x, k*2+1, si, sj, ti, cj);
            T v1 = update(i, j, x, k*2+2, si, cj, ti, tj);
            return dat[k] = min(v0, v1);
        }else{
            T v0 = update(i, j, x, k*2+1, si, sj, ci, tj);
            T v1 = update(i, j, x, k*2+2, ci, sj, ti, tj);
            return dat[k] = min(v0, v1);
        }
    }
    T update(int i, int j, T x) {
        return update(i, j, x, 0, 0, 0, h, w);
    }

    T query(int ssi, int ssj, int tti, int ttj, int k, int si, int sj, int ti, int tj) {
        if(ti <= ssi || tti <= si || tj <= ssj || ttj <= sj) return init;
        if(ssi <= si && ti <= tti && ssj <= sj && tj <= ttj) return dat[k];
        int di = ti-si;
        int dj = tj-sj;
        int ci = (si+ti)/2;
        int cj = (sj+tj)/2;
        if(di < dj){
            T v0 = query(ssi, ssj, tti, ttj, k*2+1, si, sj, ti, cj);
            T v1 = query(ssi, ssj, tti, ttj, k*2+2, si, cj, ti, tj);
            return min(v0, v1);
        }else{
            T v0 = query(ssi, ssj, tti, ttj, k*2+1, si, sj, ci, tj);
            T v1 = query(ssi, ssj, tti, ttj, k*2+2, ci, sj, ti, tj);
            return min(v0, v1);
        }
    }
    T query(int si, int sj, int ti, int tj) {
        return query(si, sj, ti, tj, 0, 0, 0, h, w);
    }
};//}}}
SGT2<int> sgt;
int main() {
    while(true){
        int h, w, q;cin >> h >> w >> q;
        if(h == 0 && w == 0 && q == 0) break;
        sgt = SGT2<int>(h, w, INT_MAX);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int g;cin >> g;
                sgt.update(i, j, g);
            }
        }
        for(int i=0;i<q;i++){
            int si, sj, ti, tj;cin >> si >> sj >> ti >> tj;
            ti++;tj++;
            cout << sgt.query(si, sj, ti, tj) << endl;
        }
    }
    return 0;
}
