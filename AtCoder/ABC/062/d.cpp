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
    int n;cin >> n;
    vector<int> a(3*n);
    inc(i, 0, 3*n){
        cin >> a[i];
    }
    priority_queue<int, vector<int>, greater<int>> bp;
    priority_queue<int> cp;
    vector<LL> b(n+1), c(n+1);
    b[0] = 0;
    c[0] = 0;
    //cout << "OK" << endl;
    inc(i, 0, n){
        bp.push(a[i]);
        b[0] += a[i];
        cp.push(a[2*n+i]);
        c[0] += a[2*n+i];
    }
    inc(i, 0, n){
        if(bp.top() < a[n+i]){
            b[i+1] = b[i]-bp.top()+a[n+i];
            bp.pop();
            bp.push(a[n+i]);
        }else{
            b[i+1] = b[i];
        }
        if(cp.top() > a[2*n-i-1]){
            c[i+1] = c[i]-cp.top()+a[2*n-i-1];
            cp.pop();
            cp.push(a[2*n-i-1]);
        }else{
            c[i+1] = c[i];
        }
    }
    LL ans = LLONG_MIN;
    inc(i, 0, n+1){
        ans = max(ans, b[i]-c[n-i]);
    }
    cout << ans << endl;
    return 0;
}
