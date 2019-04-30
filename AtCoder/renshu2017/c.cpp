// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL n, t;cin >> n >> t;
    vector<P> p(n);
    vector<int> minus(n);
    LL total = 0;
    for(int i=0;i<n;i++){
        int a, b;cin >> a >> b;
        p[i].first = a;
        p[i].second = b;
        total += a;
        minus[i] = b-a;
    }

    sort(p.begin(), p.end());
    sort(minus.begin(), minus.end());

    //int asum[100005], bsum[100005];
    //asum[0] = 0;
    //bsum[0] = 0;
    //for(int i=1;i<=n;i++){
        //asum[i] = asum[i-1] + p[i-1].first;
        //bsum[i] = bsum[i-1] + p[i-1].second;
    //}
    int ans = -1;
    for(int i=0;i<n;i++){
        if(total <= t){
            ans = i;
            break;
        }
        total += minus[i];
        if(i == n-1 && total <= t){
            ans = n;
        }
    }
    //for(int i=0;i<=n;i++){
        //if(asum[i] + (bsum[n] - bsum[i]) <= t){
            //ans = n - i;
        //}
    //}
    cout << ans << endl;
    return 0;
}
