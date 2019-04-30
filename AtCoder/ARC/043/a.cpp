// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL n, a, b;cin >> n >> a >> b;
    vector<LL> s(n);
    LL sum = 0;
    for(int i=0;i<n;i++){
        cin >> s[i];
        sum += s[i];
    }
    LL mmax = *max_element(s.begin(), s.end());
    LL mmin = *min_element(s.begin(), s.end());
    if(mmax-mmin == 0){
        cout << -1 << endl;
        return 0;
    }
    double p = b/double(mmax-mmin);
    double q = a-p*sum/n;
    printf("%.8f %.8f\n", p, q);
    return 0;
}
