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
    while(true){
        int r0, w, c, r;cin >> r0 >> w >> c >> r;
        if(r0 == 0) break;
        if(double(r0/double(w)) >= double(c)){
            cout << 0 << endl;
            continue;
        }
        cout << (c*w-r0+r-1)/r << endl;
    }
    return 0;
}
