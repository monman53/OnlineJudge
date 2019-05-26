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
char c[16][16];

pair<int, int> dfs(int cnt) {
    pair<int, int> res = {0, 0};
    bool f = false;
    inc(i, 0, h){
        inc(j, 0, w){
            if(c[i][j] == '@') continue;
            if(c[i][j] == '#') continue;
            {
                inc(d, 0, 2){
                    bool ok = true;
                    inc(k, 0, 2){
                        inc(l, 0, 100){
                            int ni = i + di[d+k*2]*l;
                            int nj = j + dj[d+k*2]*l;
                            if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                            if(c[ni][nj] == '#') ok = false;
                            if(c[ni][nj] == '@') break;
                        }
                    }
                    if(!ok) continue;
                    char tmp[16][16];
                    // save
                    inc(ii, 0, h){
                        inc(jj, 0, w){
                            tmp[i][j] = c[i][j];
                        }
                    }
                    // solve
                    inc(k, 0, 2){
                        inc(l, 0, 100){
                            int ni = i + di[d+k*2]*l;
                            int nj = j + dj[d+k*2]*l;
                            if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                            if(c[ni][nj] == '@') break;
                            c[ni][nj] = '@';
                        }
                    }

                    auto ans = dfs(cnt+1);
                    if(cnt%2 == 0){
                        if(ans.fi > 0){
                            f = true;
                            res.fi += ans.fi;
                            res.se += ans.se;
                        }
                    }else{
                        if(ans.se > 0){
                            f = true;
                            res.fi += ans.fi;
                            res.se += ans.se;
                        }
                    }
                    
                    // restore
                    inc(ii, 0, h){
                        inc(jj, 0, w){
                            c[i][j] = tmp[i][j];
                        }
                    }
                }
            }
        }
    }
    if(!f){
        if(cnt%2 == 0){
            return {0, 1};
        }else{
            return {1, 0};
        }
    }else{
        return res;
    }
}

void solve(int idx) {
    cin >> h >> w;
    inc(i, 0, h){
        string s;
        cin >> s;
        inc(j, 0, w){
            c[i][j] = s[j];
        }
    }
    auto ans = dfs(0);
    cout << ans.fi << " " << ans.se << endl;
    cout << "Case #" << idx << ": " << ans.fi << endl;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        solve(i+1);
    }
    return 0;
}
