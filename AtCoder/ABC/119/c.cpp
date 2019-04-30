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

int n;
int l[8];
int hoge[8];
int a[3];
int ans = INF;

void eval() {
    //inc(i, 0, n) cout << hoge[i];
    //cout << endl;
    int res = 0;
    inc(k, 0, 3){
        int sum = 0;
        int cnt = 0;
        inc(i, 0, n){
            if(hoge[i] == k){
                sum += l[i];
                cnt++;
            }
        }
        if(cnt == 0) return;
        res += (cnt-1)*10 + abs(sum-a[k]);
    }
    ans = min(ans, res);
}

void dfs(int i) {
    if(i == n){
        eval();
        return;
    }
    inc(k, 0, 4){
        hoge[i] = k;
        dfs(i+1);
    }
    return;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> n;
    inc(i, 0, 3) cin >> a[i];
    inc(i, 0, n) cin >> l[i];
    dfs(0);
    cout << ans << endl;
    return 0;
}
