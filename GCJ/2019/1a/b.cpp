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

void solve(int idx) {
    int n, m;cin >> n >> m;
    int ans = 0;
    inc(i, 0, n){
        inc(i, 0, 18){
            cout << "18";
            if(i < 17){
                cout << " ";
            }
        }
        cout << endl;
        int cnt = 0;
        inc(i, 0, 18){
            int a;cin >> a;
            cnt += a;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    int d;cin >> d;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        solve(i+1);
    }
    return 0;
}
