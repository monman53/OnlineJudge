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
    int n;cin >> n;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    for(int i=0;i<n;i++){
        double M, m;cin >> M >> m;
        if(M >= 35) a++;
        if(M >= 30 && M < 35) b++;
        if(M >= 25 && M < 30) c++;
        if(m >= 25) d++;
        if(M >= 0 && m < 0) e++;
        if(M < 0) f++;
    }
    printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
    return 0;
}
