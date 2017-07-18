// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
// #define EQ(a, b)    (abs((a)-(b)) < EPS)
inline bool EQ(double a, double b) {return abs(a-b) < EPS;}
// ciling(x/y) = (x+y-1)/y

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
    int n, m;cin >> n >> m;
    vector<vector<bool>> r(n, vector<bool>(n, false));
    for(int i=0;i<m;i++){
        int x, y;cin >> x >> y;
        x--;y--;
        r[x][y] = r[y][x] = true;
    }
    int ans = 1;
    for(int i=0;i<(1<<n);i++){
        bitset<12> bit(i);
        bool flag = true;
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(bit[j] && bit[k] && !r[j][k]){
                    flag = false;
                }
            }
        }
        if(flag) ans = max(ans, (int)bit.count());
    }
    cout << ans << endl;
    return 0;
}
