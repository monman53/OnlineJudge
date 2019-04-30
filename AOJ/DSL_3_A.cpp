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
    int n, s;cin >> n >> s;
    int sum[100005];
    sum[0] = 0;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        sum[i+1] = sum[i] + a;
    }
    int r = 1;
    int l = 0;
    int ans = 100005;
    while(r <= n){
        int ssum = sum[r]-sum[l];
        if(ssum < s){
            r++;
        }
        if(ssum >= s){
            ans = min(ans, r-l);
            if(l == r-1){
                l++;
                r++;
            }else{
                l++;
            }
        }
    }
    if(ans == 100005) ans = 0;
    cout << ans << endl;
    return 0;
}
