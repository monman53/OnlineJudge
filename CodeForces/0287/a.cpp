// header {{{
// #define NDEBUG
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

int main() {
    int c[4][8];
    for(int i=0;i<4;i++){
        string s;cin >> s;
        for(int j=0;j<4;j++){
            c[i][j] = (s[j]=='#' ? 1 : 0);
        }
    }
    bool flag = false;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int n = c[i][j] + c[i][j+1] + c[i+1][j] + c[i+1][j+1];
            if(n != 2) flag = true;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}
