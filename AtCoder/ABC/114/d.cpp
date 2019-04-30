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

vector<int> p;
vector<int> cnt;
int size = 0;

int f(int n, int ans) {
    if(n == size){
        if(ans == 75){
            return 1;
        }else{
            return 0;
        }
    }

    if(ans > 75) return 0;
    int res = 0;
    for(int i=0;i<=cnt[n];i++){
        res += f(n+1, ans*(i+1));
    }
    return res;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    map<int, int> mp;
    for(int i=1;i<=n;i++){
        int m = i;
        while(m != 1){
            for(int j=2;j<=m;j++){
                if(m%j == 0){
                    mp[j]++;
                    m /= j;
                    break;
                }
            }
        }
    }
    for(auto kv : mp){
        p.pb(kv.first);
        cnt.pb(kv.second);
    }
    size = cnt.size();

    cout << f(0, 1) << endl;
    return 0;
}
