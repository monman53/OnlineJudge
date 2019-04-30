// header {{{
#include <bits/stdc++.h>
using namespace std;

// {u}{int,long,llong}_{max,min}
#define inf         int_max/3
#define llinf       llong_max/3
#define mod         (1000000007ll)
#define moda(a, b)  a=((a)+(b))%mod
#define modp(a, b)  a=((a)*(b))%mod
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
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
    std::ios::sync_with_stdio(false);
    string a, b;cin >> a >> b;
    string s = a+b;
    int n = stoi(s);
    string ans = "No";
    for(int i=1;i*i<=n;i++){
        if(i*i == n) ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}
