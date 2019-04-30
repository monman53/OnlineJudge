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

char g[100][100];
int r, c, k;

bool solve() {
    cin >> r >> c >> k;
    int dn = r*c - k;
    if(r == 1 && c == 1 && k == 0){
        return false;
    }
    if(dn == 1){
        return false;
    }
    inc(i, 0, r){
        inc(j, 0, c){
            g[i][j] = 'N';
        }
    }
    inc(m, 0, dn){
        int i = dn/c;
        int j = dn%c;
        if(j == c-1){
            g[i][j] = 'W';
        }else{
            g[i][j] = 'E';
        }
    }
    return true;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        cout << "Case #" << i+1 << ": ";
        if(solve()){
            cout << "POSSIBLE" << endl;
        }else{
            cout << "IMPOSSIBLE" << endl;
            inc(i, 0, r){
                inc(j, 0, c){
                    cout << g[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
