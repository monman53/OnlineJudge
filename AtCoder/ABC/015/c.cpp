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
#define CILING(a, b)    (((a)+(b)-1)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

int n, k;
int t[5][5];
bool ans = false;

void dfs(int i, int sum){
    if(i == n){
        if(sum == 0){
            ans = true;
        }
        return; 
    }

    for(int j=0;j<k;j++){
        dfs(i+1, sum ^ t[i][j]);
    }
}

int main() {
    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin >> t[i][j];
        }
    }
    dfs(0, 0);
    cout << (ans ? "Found" : "Nothing") << endl;
    return 0;
}
