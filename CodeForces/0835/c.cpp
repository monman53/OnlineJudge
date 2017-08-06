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

// Segment tree {{{
struct SGT {
    /* vector<T> dat; */
    int dat[16*100*100][11];
    /* int n;  */
    /* T init; */
    SGT() {
        /* this->n     = n;            */
        /* this->init  = init;         */
        /* dat = vector<T>(4*n, init); */
        for(int i=0;i<16*100*100;i++){
            for(int j=0;j<11;j++){
                dat[i][j] = 0;
            }
        }
    }
    int update(int i, int j, int c, int x, int k, int si, int sj, int ti, int tj) {
        if(i < si || ti <= i || j < sj || tj <= j) return dat[k][c];
        if(si == ti-1 && sj == tj-1) return dat[k][c] += x;
        if(si == ti-1){
            int v0 = update(i, j, c, x, k*4+1, si, sj, ti, (sj+tj)/2);
            int v1 = update(i, j, c, x, k*4+2, si, (sj+tj)/2, ti, tj);
            return dat[k][c] = v0 + v1;
        }
        if(sj == tj-1){
            int v2 = update(i, j, c, x, k*4+3, si, sj, (si+ti)/2, tj);
            int v3 = update(i, j, c, x, k*4+4, (si+ti)/2, sj, ti, tj);
            return dat[k][c] = v2 + v3;
        }
        int v0 = update(i, j, c, x, k*4+1, si, sj, (si+ti)/2, (sj+tj)/2);
        int v1 = update(i, j, c, x, k*4+2, si, (sj+tj)/2, (si+ti)/2, tj);
        int v2 = update(i, j, c, x, k*4+3, (si+ti)/2, sj, ti, (sj+tj)/2);
        int v3 = update(i, j, c, x, k*4+4, (si+ti)/2, (sj+tj)/2, ti, tj);
        return dat[k][c] = v0 + v1 + v2 + v3;
    }
    // [a, b)の所望の値．[l, r)はノードkに対応する区間．
    int find(int ssi, int ssj, int tti, int ttj, int k, int si, int sj, int ti, int tj, int c) {
        if(tti <= si || ti <= ssi || ttj <= sj || tj <= ssj) return 0;
        if(ssi <= si && ssj <= sj && ti <= tti && tj <= ttj) return dat[k][c];
        if(si == ti-1){
            int v0 = find(ssi, ssj, tti, ttj, k*4+1, si, sj, ti, (sj+tj)/2, c);
            int v1 = find(ssi, ssj, tti, ttj, k*4+2, si, (sj+tj)/2, ti, tj, c);
            return v0 + v1;
        }
        if(sj == tj-1){
            int v2 = find(ssi, ssj, tti, ttj, k*4+3, si, sj, (si+ti)/2, tj, c);
            int v3 = find(ssi, ssj, tti, ttj, k*4+4, (si+ti)/2, sj, ti, tj, c);
            return v2 + v3;
        }
        int v0 = find(ssi, ssj, tti, ttj, k*4+1, si, sj, (si+ti)/2, (sj+tj)/2, c);
        int v1 = find(ssi, ssj, tti, ttj, k*4+2, si, (sj+tj)/2, (si+ti)/2, tj, c);
        int v2 = find(ssi, ssj, tti, ttj, k*4+3, (si+ti)/2, sj, ti, (sj+tj)/2, c);
        int v3 = find(ssi, ssj, tti, ttj, k*4+4, (si+ti)/2, (sj+tj)/2, ti, tj, c);
        return v0 + v1 + v2 + v3;
    }
    // interfaces
    void update(int i, int j, int c, int x) {
        update(i, j, c, x, 0, 0, 0, 100, 100);
    }
    int find(int si, int sj, int ti, int tj, int c) {
        return find(si, sj, ti, tj, 0, 0, 0, 100, 100, c);
    }
};//}}}

int main() {
    SGT sgt;
    int n, q, c;cin >> n >> q >> c;
    for(int i=0;i<n;i++){
        int x, y, s;cin >> x >> y >> s;
        x--;y--;
        for(int i=0;i<11;i++){
            sgt.update(x, y, i, (s+i)%(c+1));
        }
    }
    for(int i=0;i<q;i++){
        int t, si, sj, ti, tj;cin >> t >> si >> sj >> ti >> tj;
        si--;sj--;
        cout << sgt.find(si, sj, ti, tj, t%(c+1)) << endl;
    }
    return 0;
}
