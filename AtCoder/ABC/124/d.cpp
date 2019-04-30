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

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    string s;cin >> s;
    char b = '1';
    int cnt = 0;
    int p = 0;
    vector<int> v;
    inc(i, 0, n){
        if(s[i] != b){
            v.pb(cnt);
            p = 1-p;
            cnt = 1;
        }else{
            cnt++;
        }
        b = s[i];
    }
    v.pb(cnt);
    if(v.size()%2 == 0){
        v.pb(0);
    }
    int m = v.size();
    
    int l = 0;
    int r = min(2*k, m-1);
    int ans = 0;
    inc(i, 0, r+1){
        ans += v[i];
    }
    int now = ans;
    while(true){
        l += 2;
        r += 2;
        if(r >= m) break;
        now -= v[l-2];
        now -= v[l-1];
        now += v[r-1];
        now += v[r];
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}
