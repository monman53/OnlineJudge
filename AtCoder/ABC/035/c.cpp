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
    int n, q;cin >> n >> q;
    vector<int> line(n+1, 0);
    for(int i=0;i<q;i++){
        int l, r;cin >> l >> r;
        l--;r--;
        line[l]++;
        line[r+1]--;
    }
    int now = 0;
    for(int i=0;i<n;i++){
        now += line[i];
        cout << (now%2==0 ? 0 : 1);
    }
    cout << endl;
    return 0;
}
