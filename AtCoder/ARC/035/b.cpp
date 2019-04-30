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
    int n;cin >> n;
    map<int, int> m;
    vector<int> a(n);
    inc(i, 0, n){
        cin >> a[i];
        m[a[i]]++;
    }
    sort(a.begin(), a.end());
    LL ans1 = 0;
    LL sum = 0;
    inc(i, 0, n){
        sum += a[i];
        //MODA(ans1, sum);
        ans1 += sum;
    }
    LL ans2 = 1;
    for(auto kv : m){
        while(kv.second > 0){
            MODP(ans2, kv.second);
            kv.second--;
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
