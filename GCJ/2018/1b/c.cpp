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

int m;
int g[100];
int a[100], b[100];

void del(int k){
    if(g[k] > 0){
        g[k]--;
        return;
    }
    del(a[k]);
    del(b[k]);
    return;
}

bool ok(int k, set<int> s){
    if(g[k] > 0){
        g[k]--;
        return true;
    }
    if(s.find(k) != s.end()){
        return false;
    }
    s.insert(k);
    if(ok(a[k], s) && ok(b[k], s)){
        return true;
    }else{
        return false;
    }
}

int solve() {
    cin >> m;
    inc(i, 0, m){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }
    inc(i, 0, m){
        cin >> g[i];
    }

    int res = g[0];
    g[0] = 0;
    set<int> dummy;
    while(ok(0, dummy)){
        res++;
    }

    return res;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        printf("Case #%d: %d\n", i+1, solve());
    }
    return 0;
}
