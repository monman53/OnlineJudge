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


LL cnt(LL n, LL i) {
    if(i > n) return 0;
//    cout << n/(i*2)*i << endl;
    return n/(i*2)*i + max(0LL, n%(i*2LL)-i+1);
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    LL a, b;
    cin >> a >> b;
    LL ans = 0;
//    while(true){
//        cin >> a >> b;
//        cout << cnt(a, b) << endl;
//    }
//    cout << cnt(a, b) << endl;
    for(LL i=1LL;i<=b;i<<=1LL){
        //if(i > b) break;
        if((cnt(b, i)-cnt(max(a-1LL, 0LL), i))%2 == 0){
            ans += 0;
        }else{
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}
