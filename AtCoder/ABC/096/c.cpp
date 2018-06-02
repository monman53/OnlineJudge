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

int h, w;
vector<string> c;

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> h >> w;
    c.resize(h);
    inc(i, 0, h) cin >> c[i];
    string ans = "Yes";
    inc(i, 0, h){
        inc(j, 0, w){
            int cnt = 0;
            if(c[i][j] == '.') continue;
            inc(k, 0, 4){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if(c[ni][nj] == '#') cnt++;
            }
            if(cnt == 0) ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}
