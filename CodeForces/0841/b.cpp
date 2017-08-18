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
    int n;cin >> n;
    /* int count[2] = {0, 0}; */
    /* LL sum = 0; */
    bool flag = false;
    int a;
    for(int i=0;i<n;i++){
        /* LL a;cin >> a; */
        /* count[a%2]++;  */
        /* sum += a;      */
        scanf("%d", &a);
        if(a%2 == 1) flag = true;
    }
    cout << (flag ? "First" : "Second") << endl;
    /* cout << (count[0] >= count[1] ? "Second" : "First") << endl; */
    /* if(sum%2 == 1){                   */
    /*     cout << "First" << endl;      */
    /* }else{                            */
    /*     if(count[1] > 0){             */
    /*         cout << "First" << endl;  */
    /*     }else{                        */
    /*         cout << "Second" << endl; */
    /*     }                             */
    /* }                                 */
    return 0;
}
