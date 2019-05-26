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

int c[1000][1000];
using P = pair<int, int>; 

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int ans = 0;
    int h, w;cin >> h >> w;
    inc(i, 0, h){
        inc(j, 0, w){
            c[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    inc(i, 0, h){
        string s;cin >> s;
        inc(j, 0, w){
            if(s[j] == '#'){
                q.push(P(i, j));
                c[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        inc(k, 0, 4){
            int ni = x.fi + di[k];
            int nj = x.se + dj[k];
            if(ni < 0 || ni >= h || nj < 0 || nj > w) continue;
            if(c[ni][nj] != -1) continue;
            c[ni][nj] = c[x.fi][x.se]+1;
            ans = max(ans, c[ni][nj]);
            q.push(P(ni, nj));
        }
    }
    cout << ans << endl;
    return 0;
}
