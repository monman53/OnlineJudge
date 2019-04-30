// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    int n;cin >> n;
    int c[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> c[i][j];
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans += min(c[i][j], c[j][i]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
