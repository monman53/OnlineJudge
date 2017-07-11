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
#include <tuple>
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

struct V {
    vector<P> e;
};

int main() {
    ll n, m;cin >> n >> m;
    vector<V> v(n);
    for(int i=0;i<n;i++){
        int f, t;ll c;
        cin >> f >> t >> c;
        v[f].e.push_back({t, c});
        v[t].e.push_back({f, c});
    }
    return 0;
}
