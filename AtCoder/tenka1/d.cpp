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
    LL n, k;cin >> n;cin >> k;
    vector<LL> a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    LL sum = 0;
    for(int i=0;i<n;i++){
        if((a[i] | k) == k){
            sum += b[i];
        }
    }
    for(LL i=1;i<=k;i<<=1){
        if((k & i) == 0) continue;
        LL ssum = 0;
        LL kk = (k & (~i)) | (i-1);
        for(int j=0;j<n;j++){
            if(a[j] > k) continue;
            if((a[j] | kk) != kk) continue;
            ssum += b[j];
        }
        sum = max(sum, ssum);
    }
    printf("%lld\n", sum);

    return 0;
}
