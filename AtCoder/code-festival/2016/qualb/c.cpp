// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL w, h;cin >> w >> h;
    vector<LL> p(w), q(h);
    inc(i, 0, w) cin >> p[i];
    inc(i, 0, h) cin >> q[i];
    int np = w+1;
    int nq = h+1;
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    int i = 0;
    int j = 0;
    LL ans = 0;
    while(i < w || j < h){
        if(i == w){
            ans += np*q[j];
            nq--;
            j++;
            continue;
        }
        if(j == h){
            ans += nq*p[i];
            np--;
            i++;
            continue;
        }
        if(p[i] < q[j]){
            ans += nq*p[i];
            np--;
            i++;
        }else{
            ans += np*q[j];
            nq--;
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}
