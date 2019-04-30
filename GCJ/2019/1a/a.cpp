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
    int r, c;
    cin >> r >> c;
    int sum = r*c;
    bool rev = (c < r);
    if(rev){
        swap(c, r);
    }

    if((r == 2 && c < 5) || (r == 3 && c == 3)){
        cout << "Case #" << idx << ": IMPOSSIBLE" << endl;
        return;
    }else{
        cout << "Case #" << idx << ": POSSIBLE" << endl;
    }

    int tmp[20][20];
    int ans[20][20];
    inc(i, 0, 20){
        inc(j, 0, 20){
            tmp[i][j] = 0;
            ans[i][j] = 0;
        }
    }

    int o = 0;
    int cnt = 1;
    while(r > 0){
        if(r == 4 && c == 4){
            tmp[0][0] = 9;tmp[0][1] =16;tmp[0][2] = 6;tmp[0][3] = 2;
            tmp[1][0] = 7;tmp[1][1] = 1;tmp[1][2] =12;tmp[1][3] =15;
            tmp[2][0] =13;tmp[2][1] =10;tmp[2][2] = 3;tmp[2][3] = 5;
            tmp[3][0] = 4;tmp[3][1] =8;tmp[3][2] =14;tmp[3][3] =11;
            break;
        }
        if(r > 3 || r == 2){
            inc(i, 0, c){
                tmp[o+0][i] = cnt++;
                tmp[o+1][(i+3)%c] = cnt++;
            }
            o += 2;
            r -= 2;
        }else{
            inc(i, 0, c){
                tmp[o+0][i]       = cnt++;
                tmp[o+1][(i+2)%c] = cnt++;
                tmp[o+2][i]       = cnt++;
            }
            o += 3;
            r -= 3;
        }
    }

    inc(i, 0, 20){
        inc(j, 0, 20){
            if(rev){
                ans[i][j] = tmp[j][i];
            }else{
                ans[i][j] = tmp[i][j];
            }
            //cout << ans[i][j] << " ";
        }
        //cout << endl;
    }

    inc(k, 1, sum+1){
        inc(i, 0, 20){
            inc(j, 0, 20){
                if(ans[i][j] == k){
                    cout << i+1 << " " << j+1 << endl;
                }
            }
        }
    }

    return;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        solve(i+1);
    }
    return 0;
}
