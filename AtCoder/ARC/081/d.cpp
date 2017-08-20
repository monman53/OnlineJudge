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

int n;
int m;
LL memo[53][3][3];
vector<char> c[2];

LL dfs(int k, int s, int t) {
    if(memo[k][s][t] != -1) return memo[k][s][t];
    LL sum = 0;
    bool cflag = (c[0][k] == c[1][k]);
    if(cflag && s != t) return 0;
    if(!cflag && s == t) return 0;
    if(k == m-1) return 1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i != s && j != t){
                sum = (sum+dfs(k+1, i, j))%MOD;
            }
        }
    }
    /* if(sum > 0) cout << k << " " << s << " " << t << ":" << sum << endl; */
    return memo[k][s][t] = sum;
}

int main() {
    cin >> n;
    for(int i=0;i<2;i++){
        string s;cin >> s;
        char b = ' ';
        for(int j=0;j<n;j++){
            if(s[j] != b) c[i].push_back(s[j]);
            b = s[j];
        }
    }
    m = c[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                memo[i][j][k] = -1;
            }
        }
    }
    LL ans = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans = (ans+dfs(0, i, j))%MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
