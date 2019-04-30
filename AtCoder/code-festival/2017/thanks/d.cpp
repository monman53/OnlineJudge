// header {xs
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

// 最大公約数
LL gcd(LL x, LL y) {
    return y ? gcd(y, x%y) : x;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    if(n == m){
        cout << 0 << endl;
        return 0;
    }
    if(n >= m && n%m == 0){
        cout << 0 << endl;
        return 0;
    }

    int g = gcd(m, n);
    cout << (m/g-1)*g << endl;
    return 0;
}
