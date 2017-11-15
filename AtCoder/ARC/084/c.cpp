// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    //for(int i=0;i<n;i++) cout << a[i] << " ";
    //cout << endl;
    //for(int i=0;i<n;i++) cout << b[i] << " ";
    //cout << endl;
    //for(int i=0;i<n;i++) cout << c[i] << " ";
    //cout << endl;

    vector<LL> a_ans(n, 0), b_ans(n, 0);
    vector<LL> b_sum(n, 0);

    for(int i=0;i<n;i++){
        b_ans[i] = c.end() - upper_bound(c.begin(), c.end(), b[i]);
        //cout << b_ans[i] << " ";
    }
    //cout << endl;

    b_sum[n-1] = b_ans[n-1];
    for(int i=n-2;i>=0;i--){
        b_sum[i] = b_sum[i+1] + b_ans[i];
    }

    LL ans = 0;
    for(int i=0;i<n;i++){
        int p = b.end() - upper_bound(b.begin(), b.end(), a[i]);
        p = n - p;
        if(p == n) continue;
        ans += b_sum[p];
    }

    cout << ans << endl;

    return 0;
}
