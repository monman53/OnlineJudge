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
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    LL cnt[5] = {0, 0, 0, 0, 0};
    inc(i, 0, n){
        string s;cin >> s;
        switch(s[0]){
            case 'M':cnt[0]++;break;
            case 'A':cnt[1]++;break;
            case 'R':cnt[2]++;break;
            case 'C':cnt[3]++;break;
            case 'H':cnt[4]++;break;
        }
    }
    LL ans = 0;
    vector<bool> v = {0, 0, true, true, true};
    do{
        LL a = 1;
        inc(i, 0, 5){
            if(v[i]){
                a *= cnt[i];
            }
        }
        ans += a;
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}
