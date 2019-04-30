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
    int k;cin >> k;
    if(k == 0){
        cout << "a" << endl;
        return 0;
    }
    for(int i=0;i<ALPHABET;i++){
        int j = 0;
        for(;;){
            if(j*(j+1)/2 <= k){
                j++;
            }else{
                j--;
                break;
            }
        }
        //cout << k << " " << j << endl;
        if(j > 0){
            for(int l=0;l<j+1;l++){
                cout << char('a'+i);
            }
        }
        k -= j*(j+1)/2;
    }
    cout << endl;
    return 0;
}
