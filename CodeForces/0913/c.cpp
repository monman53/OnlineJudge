// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int n;
vector<LL> c;

LL solve(LL l){
    vector<LL> res;
    if(l == 0) return 0;
    vector<pair<double, int>> v;
    for(int i=0;i<n;i++){
        LL a = 1<<i;
        if(l <= a){
            res.push_back(c[i]);
        }else{
            //res.push_back(c[i]*(l/a) + solve(l%a));
            v.push_back({double(c[i])/a, i});
        }
    }
    if((int)v.size() != 0){
        sort(v.begin(), v.end());
        int ii = v[0].second;
        LL a = 1<<ii;
        res.push_back(l/a*c[ii]+solve(l%a));
    }
    return *min_element(res.begin(), res.end());
}

int main() {
    std::ios::sync_with_stdio(false);
    LL l;cin >> n >> l;
    c.resize(n);
    inc(i, 0, n) cin >> c[i];
    cout << solve(l) << endl;
    return 0;
}
