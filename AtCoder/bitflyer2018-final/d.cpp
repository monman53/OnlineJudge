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

using LL  = unsigned long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

vector<LL> make_bases(vector<LL> as) {
    vector<LL> res;
    for(auto a : as){
        for(auto base : res){
            if(base & (-base) & a){
                a ^= base;
            }
        }
        if(a == 0ull){
            continue;
        }
        for(auto &base : res) {
            if(a & (-a) & base){
                base ^= a;
            }
        }
        res.pb(a);
    }
    return res;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<LL> a(n), b(n);
    inc(i, 0, n) cin >> a[i];
    inc(i, 0, n) cin >> b[i];

    vector<LL> bases = make_bases(a);
    //for(auto base : bases){
        //bitset<64> bit(base);
        //bitset<64> bit2(-base);
        //cout << bit.to_string() << " " << bit2.to_string() << endl;
    //}
    inc(i, 0, n){
        LL c = a[i]^b[i];
        for(auto base : bases){
            if(base & (-base) & c){
                c ^= base;
            }
        }
        if(c != 0ull){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
