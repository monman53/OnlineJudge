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
    int h, w;cin >> h >> w;
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans[100][100];
    int now = 0;
    for(int k=0;k<h*w;k++){
        int i = k/w;
        int j = (k/w%2 == 0 ? k%w : w - k%w - 1);
        ans[i][j] = now;
        a[now]--;
        if(a[now] == 0) now++;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << ans[i][j]+1 << " ";
        }
        cout << endl;
    }
    return 0;
}
