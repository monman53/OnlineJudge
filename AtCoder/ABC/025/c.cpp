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
// }}}

int b[3][3], c[3][3];
int a[3][3];

using P = pair<int, pair<int, int>>;

P score(){
    int d=0, e=0;
    inc(i, 0, 2){
        inc(j, 0, 3){
            if(a[i][j] == a[i+1][j]){
                d += b[i][j];
            }else{
                e += b[i][j];
            }
        }
    }
    inc(i, 0, 3){
        inc(j, 0, 2){
            if(a[i][j] == a[i][j+1]){
                d += c[i][j];
            }else{
                e += c[i][j];
            }
        }
    }
    return {d-e, {d, e}};
}

P solve(int k) {
    if(k == 9) return score();
    P res = (k%2==0 ? P{-100000, {0, 0}} : P{100000, {0, 0}});
    inc(i, 0, 3){
        inc(j, 0, 3){
            if(a[i][j] == -1){
                if(k%2==0){
                    a[i][j] = 0;
                    res = max(res, solve(k+1));
                }else{
                    a[i][j] = 1;
                    res = min(res, solve(k+1));
                }
                a[i][j] = -1;
            }
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    memset(a, -1, sizeof(a));
    inc(i, 0, 2){
        inc(j, 0, 3){
            cin >> b[i][j];
        }
    }
    inc(i, 0, 3){
        inc(j, 0, 2){
            cin >> c[i][j];
        }
    }
    auto ans = solve(0);
    cout << ans.se.fi << endl;
    cout << ans.se.se << endl;
    return 0;
}
