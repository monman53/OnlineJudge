// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

LL h, w, q;
vector<LL> a, b;
vector<LL> sa, sb;
vector<LL> ssa, ssb;

LL calc(LL ci, LL cj) {
    //LL black = ssa[ci]*(sb[cj]-ssb[cj]) + ssb[cj]*(sa[ci]-ssa[ci]);
    LL black = ssa[ci]*ssb[cj] + (sa[ci]-ssa[ci])*(sb[cj]-ssb[cj]);
    LL white = sa[ci]*sb[cj] - black;
    //cout << black << " " << white << endl;
    return black-white;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> h >> w >> q;
    a.resize(h);sa.resize(h+1, 0);ssa.resize(h+1, 0);
    b.resize(w);sb.resize(w+1, 0);ssb.resize(w+1, 0);
    inc(i, 0, h){
        cin >> a[i];
        sa[i+1] = sa[i] + a[i];
        ssa[i+1] = ssa[i] + (i%2==0?a[i]:0);
    }
    inc(i, 0, w){
        cin >> b[i];
        sb[i+1] = sb[i] + b[i];
        ssb[i+1] = ssb[i] + (i%2==0?b[i]:0);
    }
    inc(i, 0, q){
        LL px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        px--;py--;
        //cout << calc(qx, qy) << endl;
        cout << calc(qx, qy) - calc(px, qy) - calc(qx, py) + calc(px, py) << endl;
    }
    return 0;
}
