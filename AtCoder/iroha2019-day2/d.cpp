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
    cin.tie(0);ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    UF_short uf(n);
    vector<pair<pair<int, int>, pair<int, int>>> v;
    inc(i, 0, m){
        int a, b, c;cin >> a >> b >> c;
        a--;
        b--;
        v.pb({{c, i+1}, {a, b}});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vector<int> ans;
    inc(i, 0, m){
        //int c = v[i].fi.fi;
        int a = v[i].se.fi;
        int b = v[i].se.se;
        if(uf.find(a) != uf.find(b)){
            ans.pb(v[i].fi.se);
            uf.unite(a, b);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto i : ans){
        cout << i << endl;
    }
    return 0;
}
