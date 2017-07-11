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

int main() {
    int n;cin >> n;
    vector<int> a(n), as;
    for(auto &aa : a) cin >> aa;
    as = a;
    sort(as.begin(), as.end());
    map<int, int> m;
    int aa = -1;
    for(int i=0,j=-1;i<n;i++){
        if(as[i] != aa) j++;
        m[as[i]] = j;
        aa = as[i];
    }
    for(int i=0;i<n;i++){
        cout << m[a[i]] << endl;
    }
    return 0;
}
