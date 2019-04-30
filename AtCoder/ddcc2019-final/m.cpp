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

const double pi = 3.141593;

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int xst, yst, xa, ya, xb, yb, xe, ye;
    cin >> xst >> yst >> xa >> ya >> xb >> yb >> xe >> ye;
    //XP,XSP,XAS,XDS,YP,YSP,YAS,YDS,AS,BS,ES
        //cout << xa+3*i << ",500,60,100," << ya+3*i << ",500,90,200," << "2000,0,0" << endl;
        //cout << xb+3*i << ",500,60,100," << yb+3*i << ",500,90,200," << "0,2000,0" << endl;
        //cout << xe <<     ",500,60,100," << ye     << ",500,90,200," << "0,0,4000" << endl;
    cout << xa << ",500,1000,1000," << ya << ",500,1000,1000,100,0,0" << endl;
    cout << xb << ",500,1000,1000," << yb << ",500,1000,1000,0,100,0" << endl;
    cout << xe << ",500,1000,1000," << ye << ",500,1000,1000,0,0,100" << endl;
    return 0;
}
