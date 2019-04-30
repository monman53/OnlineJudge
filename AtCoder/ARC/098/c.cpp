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

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    string s;cin >> s;
    vector<int> a(n+1, 0), b(n+1, 0);
    inc(i, 0, n){
        if(s[i] == 'E'){
            a[i+1] = a[i]+1;
            b[i+1] = b[i];
        }else{
            a[i+1] = a[i];
            b[i+1] = b[i]+1;
        }
    }
    int ans = n;
    inc(i, 0, n){
        //cout << a[i] << " " << a[n]-a[i+1] << "  ";
        //cout << b[i] << " " << b[n]-b[i+1] << endl;
        ans = min({ans, b[i]+a[n]-a[i+1]});
    }
    cout << ans << endl;
    return 0;
}
