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

int f[12];
int used[12];

bool same(int i, int j) {
    inc(k, 0, h){
        if(c[f[k]][i] != c[f[h-k-1]][j]) return false;
    }
    return true;
}

bool dfs2(int cnt, int flag) {
    if(cnt == w){
        return true;
    }

    bool res = false;

    inc(i, 0, w){
        if(used[i]) continue;
        inc(j, i+1, w){
            if(used[j]) continue;
            if(same(i, j)){
                used[i] = 1;
                used[j] = 1;
                return dfs2(cnt+2, flag);
            }
        }
        if(flag == 0 && same(i, i)){
            used[i] = 1;
            res |= dfs2(cnt+1, flag+1);
            used[i] = 0;
        }
        break;
    }

    return res;
}

bool dfs1(int idx, int bit) {
    bool res = false;
    int cnt = 0;
    inc(i, 0, h){
        if((bit & (1 << i)) != 0) cnt++;
    }

    if(cnt == h){
        inc(i, 0, w){
            used[i] = 0;
        }
        return dfs2(0, 0);
    }

    if(cnt == 0 && h%2 == 1){
        inc(i, 0, h){
            f[h/2] = i;
            res |= dfs1(0, bit | (1 << i));
            f[h/2] = -1;
        }
    }else{
        inc(i, 0, h){
            if((bit & (1 << i)) != 0) continue;

            inc(j, i+1, h){
                if((bit & (1 << j)) != 0) continue;

                f[idx] = i;
                f[h-idx-1] = j;
                res |= dfs1(idx+1, bit | (1 << i) | (1 << j));
                f[idx] = -1;
                f[h-idx-1] = -1;
            }
            break;
        }
    }

    return res;
}

int main() {
    cin >> h >> w;
    inc(i, 0, h){
        string s;cin >> s;
        c.pb(s);
    }

    inc(i, 0, h) f[i] = -1;

    cout << (dfs1(0, 0) ? "YES" : "NO") << endl;

    return 0;
}
