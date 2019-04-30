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

#define SIZE 200010


LL fact[SIZE] = {1, 1};

void initFact() {
    // fact
    for(LL i=2;i<SIZE;i++){
        fact[i] = fact[i-1]*i%MOD;
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    initFact();
    int n, k;cin >> n >> k;
    vector<int> v(n);
    inc(i, 0, n) cin >> v[i];
    map<int, int> mp;
    mp[v[0]]++;
    LL ans = k;
    inc(i, 1, n){
        mp[v[i]]++;
        if(i-k >= 0){
            mp[v[i-k]]--;
            if(mp[v[i-k]] == 0){
                mp.erase(v[i-k]);
            }
        }
        int u = mp.size();

        if(mp[v[i]] == 1){
            MODP(ans, (LL)(k-u+1));
        }
    }

    cout << ans << endl;
    return 0;
}
