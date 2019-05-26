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

int tag[100000];

vector<vector<int>> g;

void dfs(int t, int to, int from) {
    if(tag[to] != -1) return;
    tag[to] = t;
    for(auto next : g[to]){
        if(next == from) continue;
        dfs(t, next, to);
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    g.resize(n);
    inc(i, 0, n){
        tag[i] = -1;
    }
    inc(i, 0, m){
        int x, y;cin >> x >> y;
        x--;y--;
        int d;cin >> d;
        g[x].pb(y);
        g[y].pb(x);
    }
    inc(i, 0, n){
        if(tag[i] != -1) continue;
        dfs(i, i, -1);
    }
    set<int> st;
    inc(i, 0, n){
        st.insert(tag[i]);
    }
    cout << st.size() << endl;
    return 0;
}
