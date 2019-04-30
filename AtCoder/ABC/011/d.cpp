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

double pcomb[1005][1005];

int main() {
    std::ios::sync_with_stdio(false);
    LL n, d;cin >> n >> d;
    LL X, Y;cin >> X >> Y;
    X = abs(X);
    Y = abs(Y);
    if(X%d != 0 || Y%d != 0){
        cout << 0 << endl;
        return 0;
    }
    LL nx = X/d;
    LL ny = Y/d;
    if(nx+ny > n || (nx+ny)%2 != n%2){
        cout << 0 << endl;
        return 0;
    }

    pcomb[0][0] = 1;
    inc(i, 1, n+1){
        pcomb[i][0] = pcomb[i-1][0]/2;
    }
    inc(i, 1, n+1){
        inc(j, 1, j+1){
            pcomb[i][j] = (pcomb[i-1][j-1]+pcomb[i-1][j])/2;
        }
    }

    return 0;
}
