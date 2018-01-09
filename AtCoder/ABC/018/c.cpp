// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(r);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {1, -1};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int h, w, k;cin >> h >> w >> k;
    vector<string> c(h);
    inc(i, 0, h) cin >> c[i];
    int cnt[500][500][2];
    memset(cnt, 0, sizeof(cnt));
    inc(i, 0, h){
        inc(j, 0, w){
            inc(l, 0, 2){
                inc(m, 0, h){
                    int ni = i+di[l]*m;
                    if(ni < 0 || ni >= h) break;
                    if(c[ni][j] == 'x') break;
                    cnt[i][j][l]++;
                }
            }
        }
    }

    int ans = 0;
    inc(i, k-1, h-k+1){
        inc(j, k-1, w-k+1){
            bool flag = true;
            inc(l, 0, k){
                if(cnt[i][j+l][0] < k-l) flag = false;
                if(cnt[i][j-l][0] < k-l) flag = false;
                if(cnt[i][j+l][1] < k-l) flag = false;
                if(cnt[i][j-l][1] < k-l) flag = false;
            }
            if(flag) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
