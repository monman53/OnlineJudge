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

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int h, w;
char c[500][500];
int f[500][500];

bool dfs(int i, int j) {
    if(f[i][j] == 1) return false;
    f[i][j] = 1;
    if(c[i][j] == 'g') return true;
    if(c[i][j] == '#') return false;
    bool res = false;
    inc(k, 0, 4){
        int ni = i+di[k];
        int nj = j+dj[k];
        if(ni >= 0 && ni < h && nj >= 0 && nj < w){
            res |= dfs(ni, nj);
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> h >> w;
    memset(f, 0, sizeof(f));
    int si, sj;
    inc(i, 0, h){
        string s;cin >> s;
        inc(j, 0, w){
            c[i][j] = s[j];
            if(s[j] == 's'){
                si = i;
                sj = j;
            }
        }
    }
    cout << (dfs(si, sj) ? "Yes" : "No") << endl;
    return 0;
}
