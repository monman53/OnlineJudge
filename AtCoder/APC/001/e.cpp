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

int n;
G g;

int d[100000];

int dfs2(int from, int to){
    int cnt = 0;
    int ans;
    for(auto next : g[to]){
        if(next == from) continue;
        cnt++;
        ans = dfs2(to, next);
    }
    if(cnt == 0) return d[to] = 0;
    if(cnt == 1){
        return d[to] = ans+1;
    }
    return d[to] = 0;
}

pair<int, int> dfs(int from, int to){
    vector<int> v;
    int mmin = INT_MAX;
    for(auto next : g[to]){
        if(next == from) continue;
        auto ans = dfs(to, next);
        v.push_back(ans.first);
        if(ans.first == 1){
            mmin = min(mmin, ans.second);
        }
    }
    int m = v.size();
    if(m == 0){
        return {1, 0};
    }
    if(m == 1){
        if(mmin == d[to]){
            return {v[0]+1, mmin};
        }else{
            return {v[0], mmin};
        }
    }
    int sum = 0;
    int cnt = 0;
    inc(i, 0, m){
        if(v[i] == 1) cnt++;
        sum += v[i];
    }
    if(cnt > 0) sum--;
    if(cnt > 1){
        return {sum, mmin+1};
    }else{
        return {sum, 0};
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    g.resize(n);
    inc(i, 0, n-1){
        int a, b;cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << dfs(-1, 0).first << endl;
    return 0;
}
