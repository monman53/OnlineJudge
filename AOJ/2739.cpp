// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
// #include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
// ciling(x/y) = (x+y-1)/y

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    int n, m, t;cin >> n >> m >> t;
    vector<bool> study(t, true);
    for(int i=0;i<n;i++){
        int a;cin >> a;
        for(int j=a-m;j<min(a+m, t);j++){
            study[j] = false;
        }
    }
    int ans = 0;
    for(int i=0;i<t;i++){
        if(study[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
