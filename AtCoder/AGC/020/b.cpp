// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL k;cin >> k;
    vector<LL> a(k);
    inc(i, 0, k) cin >> a[i];
    if(a[k-1] != 2){
        cout << -1 << endl;
        return 0;
    }
    LL mmin = 2;
    LL mmax = 2;
    reverse(a.begin(), a.end());
    inc(i, 0, k){
        if(a[i] > mmax){
            cout << -1 << endl;
            return 0;
        }
        LL b = (mmin+a[i]-1)/a[i]*a[i];
        if(b > mmax){
            cout << -1 << endl;
            return 0;
        }

        // mmax
        LL ok = mmin;
        LL ng = mmax+max(a[i], mmax)*2;
        while(ng-ok>1){
            //cout << ok << " " << ng << endl;
            LL m = (ok+ng)/2;
            if(m/a[i]*a[i] <= mmax && m/a[i]*a[i] >= mmin){
                ok = m;
            }else{
                ng = m;
            }
        }
        mmax = ok;

        // mmin
        if(mmin < a[i]){
            mmin = a[i];
        }else if(mmin > a[i]){
            mmin = (mmin+a[i]-1)/a[i]*a[i];
        }

        if(mmin > mmax){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << mmin << " " << mmax << endl;
    return 0;
}
