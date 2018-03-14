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
    int c[3][3];
    string ans = "Yes";
    inc(i, 0, 3){
        inc(j, 0, 3){
            cin >> c[i][j];
        }
    }
    inc(i, 1, 3){
        inc(j, 1, 3){
            if(c[i][j-1]-c[i-1][j-1] != c[i][j]-c[i-1][j]) ans = "No";
            if(c[i-1][j]-c[i-1][j-1] != c[i][j]-c[i][j-1]) ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}
