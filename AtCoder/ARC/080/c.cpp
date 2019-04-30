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
    vector<int> a(n);
    for(auto &aa : a) cin >> aa;
    int count2 = 0;
    int count4 = 0;
    int odd = 0;
    for(int i=0;i<n;i++){
        if(a[i]%4 == 0){
            count4++;
        }else if(a[i]%2 == 0){
            count2++;
        }else{
            odd++;
        }
    }
    bool flag = false;
    if(count4 == 0){
        if(odd == 0){
            flag = true;
        }
    }else{
        if(count2 == 0){
            if(count4 >= odd-1) flag = true;
        }else{
            if(count4 >= odd) flag = true;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
