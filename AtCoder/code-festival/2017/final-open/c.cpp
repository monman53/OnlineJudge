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

int cnt[13];
int c[24];

int dfs(int d) {
    int res = 0;
    if(d == 12){
        if(cnt[12] == 1) c[12] = 1;
        int a = 1;
        res = 100;
        inc(i, 1, 25){
            if(c[i%24] == 1){
                res = min(res, a);
                a = 1;
            }else{
                a++;
            }
        }
        return res;
    }
    if(cnt[d] == 0) return dfs(d+1);
    if(cnt[d] == 1){
        c[d] = 1;
        res = max(res, dfs(d+1));
        c[d] = 0;
        c[24-d] = 1;
        res = max(res, dfs(d+1));
        c[24-d] = 0;
    }
    if(cnt[d] == 2){
        c[d] = 1;
        c[24-d] = 1;
        return dfs(d+1);
        c[d] = 0;
        c[24-d] = 0;
    }
    if(cnt[d] > 2) return 0;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> d(n);
    inc(i, 0, n){
        cin >> d[i];
        cnt[d[i]]++;
    }
    cnt[0]++;
    if(cnt[0] > 1 || cnt[12] > 1){
        cout << 0 << endl;
        return 0;
    }
    c[0] = 1;
    cout << dfs(1) << endl;
    return 0;
}
