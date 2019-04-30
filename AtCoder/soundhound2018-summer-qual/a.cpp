// header {{{
#include <bits/stdc++.h>
using namespace std;

// {u}{int,long,llong}_{max,min}
#define inf         int_max/3
#define llinf       llong_max/3
#define mod         (1000000007ll)
#define moda(a, b)  a=((a)+(b))%mod
#define modp(a, b)  a=((a)*(b))%mod
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using ll  = long long;
using g   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    string ans = "x";
    int a, b;cin >> a >> b;
    if(a+b == 15) ans = "+";
    if(a*b == 15) ans = "*";
    cout << ans << endl;
    return 0;
}
