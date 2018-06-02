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


pair<int, int> solve() {
    int s;cin >> s;
    vector<int> d(s), a(s), b(s);
    inc(i, 0, s){
        cin >> d[i] >> a[i] >> b[i];
    }

    dec(k, 2, s+1){
        int cnt = 0;
        inc(i, 0, s-k+1){
            // a
            bool flaga = true;
            vector<int> v;
            inc(j, i, i+k){
                if(d[j]+a[j] != d[i]+a[i]){
                    v.pb(j);
                }
            }
            int n = v.size();
            inc(j, 0, n){
                if(d[v[j]]-b[v[j]] != d[v[0]]-b[v[0]]){
                    flaga = false;
                }
            }

            // b
            bool flagb = true;
            v.clear();
            inc(j, i, i+k){
                if(d[j]-b[j] != d[i]-b[i]){
                    v.pb(j);
                }
            }
            n = v.size();
            inc(j, 0, n){
                if(d[v[j]]+a[v[j]] != d[v[0]]+a[v[0]]){
                    flagb = false;
                }
            }

            if(flaga || flagb) cnt++;
        }
        if(cnt > 0){
            return {k, cnt};
        }
    }

    return {s, 1};
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        auto ans = solve();
        printf("Case #%d: %d %d\n", i+1, ans.fi, ans.se);
    }
    return 0;
}
