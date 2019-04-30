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

int a[2000][2000];
int b[2001][2001];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    LL h, w;cin >> h >> w;
    LL n, m;cin >> n >> m;
    inc(i, 0, n){
        string s;cin >> s;
        inc(j, 0, m){
            a[i][j] = (s[j]=='#' ? 1 : 0);
        }
    }

    inc(i, 0, n){
        inc(j, 0, m){
            if(a[i][j] == 1){
                b[i][j]++;
                b[i][j+min(m, w-m)+1]--;
                b[i+min(n, h-n)+1][j]--;
                b[i+min(n, h-n)+1][j+min(m, w-m)+1]++;
            }
        }
    }

    inc(i, 0, 2001){
        inc(j, 1, 2001){
            b[i][j] = b[i][j-1]+b[i][j];
        }
    }

    inc(j, 0, 2001){
        inc(i, 1, 2001){
            b[i][j] = b[i-1][j]+b[i][j];
        }
    }
    
    //
    LL ans1 = 0;
    inc(i, 0, 2000){
        inc(j, 0, 2000){
            if(b[i][j] > 0) ans1++;
        }
    }

    // h
    LL ans2 = 0;
    if(h > n*2){
        inc(j, 0, 2000){
            bool f = false;
            inc(i, 0, 2000){
                if(b[i][j] > 0){
                    f = true;
                }
            }
            if(f) ans2 += h-n*2;
        }
    }

    LL ans3 = 0;
    if(w > m*2){
        inc(i, 0, 2000){
            bool f = false;
            inc(j, 0, 2000){
                if(b[i][j] > 0){
                    f = true;
                }
            }
            if(f) ans3 += w-m*2;
        }
    }

    LL ans4 = 0;
    if(h > n*2 && w > m*2 && ans1 > 0){
        ans4 = (h-n*2)*(w-m*2);
    }

    cout << ans1 + ans2 + ans3 + ans4 << endl;


    return 0;
}
