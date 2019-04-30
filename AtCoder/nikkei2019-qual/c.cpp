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

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    LL n;cin >> n;
    vector<LL> a(n), b(n);
    inc(i, 0, n) cin >> a[i] >> b[i];
    vector<pair<pair<LL, LL>, int>> aa, bb;
    inc(i, 0, n){
        aa.pb({{-abs(a[i]-b[i]), -a[i]}, i});
        bb.pb({{-abs(b[i]-a[i]), -b[i]}, i});
    }
    //sort(aa.begin(), aa.end());reverse(aa.begin(), aa.end());
    //sort(bb.begin(), bb.end());reverse(bb.begin(), bb.end());
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    vector<bool> used(n, false);
    int ai = 0;
    int bi = 0;
    LL ansa = 0;
    LL ansb = 0;
    inc(i, 0, n){
        if(i%2 == 0){
            while(used[aa[ai].se]){
                ai++;
            }
            used[aa[ai].se] = true;
            ansa += a[aa[ai].se];
        }else{
            while(used[bb[bi].se]){
                bi++;
            }
            used[bb[bi].se] = true;
            ansb += b[bb[bi].se];
        }
    }
    printf("%lld\n", ansa-ansb);
    //cout << ansa-ansb << endl;
    return 0;
}
