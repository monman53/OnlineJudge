// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

bool online(LL i, LL j, LL yi, LL yj, LL x, LL y) {
    return (j-i)*y-(yj-yi)*x == (j-i)*yi-(yj-yi)*i;
}

LL dist(LL ax, LL ay, LL bx, LL by) {
    LL dx = bx-ax;
    LL dy = by-ay;
    return dx*dx+dy*dy;
}

int main() {
    std::ios::sync_with_stdio(false);
    LL ax, ay, bx, by, cx, cy;
    cin >> ax>> ay>> bx>> by>> cx>> cy;
    string ans = "Yes";
    if(online(ax, bx, ay, by, cx, cy)){
        ans = "No";
    }
    if(dist(ax, ay, bx, by) != dist(bx, by, cx, cy)){
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}
