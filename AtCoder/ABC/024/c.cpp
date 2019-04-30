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

int main() {
    int n, d, k;cin >> n >> d >> k;
    int l[10005], r[10005];
    for(int i=0;i<d;i++){
        cin >> l[i] >> r[i];
    }
    for(int i=0;i<k;i++){
        int s, t;cin >> s >> t;

        int cl = s;
        int cr = s;
        
        for(int j=0;j<d;j++){
            if(!((l[j] < cl && r[j] < cl) ||
                 (cr < l[j] && cr < r[j]))){
                cl = min(cl, l[j]);
                cr = max(cr, r[j]);

                if(cl <= t && t <= cr){
                    cout << j+1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
