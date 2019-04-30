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

struct UF {
    vector<int> p;  // parent
    LL fuben;
    map<int, LL> mp;

    UF(int n) {
        p.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
            mp[i]++;
        }
        fuben = LL(n)*(n-1)/2;
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
        fuben -= mp[x]*mp[y];
        mp[x] += mp[y];
        p[y] = p[x];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    dec(i, 0, m){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }

    UF uf(n);

    vector<LL> ans;
    inc(i, 0, m){
        ans.pb(uf.fuben);
        uf.unite(a[i], b[i]);
    }
    dec(i, 0, m){
        cout << ans[i] << endl;
    }
    return 0;
}
