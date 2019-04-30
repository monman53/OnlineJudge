// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

struct V {
    LL v;
    vector<int> e;
};
vector<V> v;

LL sum = 0;
LL mmin = 1000000000005LL;
bool check[100005];

bool solve(int s, int t) {
    if(check[t]) return true;
    check[t] = true;
    sum += v[t].v;
    mmin = min(mmin, v[t].v);


    bool ret = false;

    for(auto ee : v[t].e){
        if(ee == s) continue;
        ret |= solve(t, ee);
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    v.resize(n);
    for(int i=0;i<n;i++){
        check[i] = false;
        cin >> v[i].v;
    }
    for(int i=0;i<m;i++){
        int x, y;cin >> x >> y;x--;y--;
        v[x].e.push_back(y);
        v[y].e.push_back(x);
    }
    LL ans = 0;
    for(int i=0;i<n;i++){
        sum = 0;
        mmin = 1000000000005LL;
        if(check[i]) continue;
        if(solve(-1, i)){
            ans += sum;
        }else{
            ans += sum-mmin;
        }
    }
    cout << ans << endl;

    return 0;
}
