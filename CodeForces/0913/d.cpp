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

LL n, T;

struct D {
    LL a, t;
};
vector<D> d;

bool solve(int m) {
    vector<LL> v;
    for(int i=0;i<n;i++){
        if(d[i].a >= m){
            v.push_back(d[i].t);
        }
    }
    sort(v.begin(), v.end());
    if((int)v.size() < m) return false;
    LL sum = 0;
    for(int i=0;i<m;i++){
        sum += v[i];
    }
    if(sum > T) return false;
    return true;
}

bool ans(int m) {
    vector<pair<LL, int>> v;
    for(int i=0;i<n;i++){
        if(d[i].a >= m){
            v.push_back({d[i].t, i});
        }
    }
    sort(v.begin(), v.end());
    if((int)v.size() < m) return false;
    LL sum = 0;
    for(int i=0;i<m;i++){
        sum += v[i].first;
    }
    if(sum > T) return false;
    cout << m << endl;
    for(int i=0;i<m;i++){
        cout << v[i].second+1 << " ";
    }
    cout << endl;
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> T;
    d.resize(n);
    inc(i, 0, n){
        LL a, t;cin >> a >> t;
        d[i] = {a, t};
    }
    int l = 0;
    int r = n+1;
    while(r-l>1){
        //cout << l << " " << r << endl;
        int c = (r+l)/2;
        if(solve(c)){
            l = c;
        }else{
            r = c;
        }
    }
    cout << l << endl;
    ans(l);
    return 0;
}
