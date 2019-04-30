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

struct BIT {
    vector<LL> bit;
    int n;
    BIT(int n) {
        bit.resize(n+1, 0);
        this->n = n;
    }
    LL query(int i) {
        LL mmax = 0;
        while(i > 0){
            mmax = max(mmax, bit[i]);
            // i & -i はiの最後の1のビット
            i -= i & -i;
        }
        return mmax;
    }
    void set(int i, LL x) {
        while(i <= n){
            bit[i] = max(bit[i], x);
            i += i & -i;
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    vector<int> t(n), d(n), d2(n);
    map<int, vector<int>> m;
    set<int> s;
    inc(i, 0, n){
        cin >> t[i] >> d[i];
        d2[i] = d[i];
        s.insert(d[i]);
        m[d[i]].pb(i);
    }

    vector<int> v;
    for(auto ss : s) v.pb(ss);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(auto dd : v){
        bool flag = false;
        for(auto i : m[dd]){
            if(d2[i] == 0){
                flag = true;
                break;
            }
            inc(j, i+1, n){
                if(d2[j] == 0 || t[j]-t[i] >= k) break;
                if(d2[j] == dd) flag = true;
            }
            dec(j, 0, i){
                if(d2[j] == 0 || t[i]-t[j] >= k) break;
                if(d2[j] == dd) flag = true;
            }
        }
        if(flag) break;
        for(auto i : m[dd]){
            d[i] = d2[i] = 0;
            inc(j, i+1, n){
                if(d2[j] == 0 || t[j]-t[i] >= k) break;
                d2[j] = 0;
            }
            dec(j, 0, i){
                if(d2[j] == 0 || t[i]-t[j] >= k) break;
                d2[j] = 0;
            }
        }
    }

    BIT bit(n);
    LL mmax = 0;
    inc(i, 0, n){
        int ng = i;
        int ok = n;
        while(ok-ng>1){
            int m = (ng+ok)/2;
            if(t[m]-t[i] >= k){
                ok = m;
            }else{
                ng = m;
            }
        }
        if(ok == n){
            mmax = max(mmax, bit.query(i)+d2[i]);
        }else{
            bit.set(ok, bit.query(i)+d2[i]);
        }
    }

    int ansmax = 0;
    LL anssum = -mmax;
    inc(i, 0, n){
        ansmax = max(ansmax, d[i]);
        anssum += d[i];
    }
    cout << ansmax << endl;
    cout << anssum << endl;

    return 0;
}
