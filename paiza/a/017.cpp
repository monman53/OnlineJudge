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

int main() {
    std::ios::sync_with_stdio(false);
    int H, W, n;cin >> H >> W >> n;
    char c[30][30];
    inc(i, 0, H) inc(j, 0, W) c[i][j] = '.';
    inc(i, 0, n){
        int h, w, x;cin >> h >> w >> x;
        inc(j, 0, H){
            bool flag = true;
            inc(k, j, H){
                inc(l, x, x+w){
                    if(c[k][l] == '#') flag = false;
                }
            }
            if(flag){
                inc(k, j, j+h){
                    inc(l, x, x+w){
                        c[k][l] = '#';
                    }
                }
                break;
            }
        }
    }

    dec(i, 0, H){
        inc(j, 0, W){
            cout << c[i][j];
        }
        cout << endl;
    }
    return 0;
}
