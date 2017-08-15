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
    int n, k;cin >> n >> k;
    int s, t, u;
    s = 2*n;
    t = u = n;
    vector<int> a(k);
    for(auto &aa : a) cin >> aa;
    for(int i=0;i<k;i++){
        while(a[i] >= 4 && t > 0 && u > 0){
            t--;
            u--;
            a[i]-=4;
        }
    }
    for(int i=0;i<k;i++){
        while(a[i] == 3 && t > 0 && u > 0){
            t--;
            u--;
            a[i]-=3;
        }
    }
    for(int i=0;i<k;i++){
        while(a[i] >= 2 && s > 0){
            s--;
            a[i]-=2;
        }
    }
    for(int i=0;i<k;i++){
        while(a[i] >= 2 && t > 0){
            t--;
            a[i]-=2;
        }
    }
    for(int i=0;i<k;i++){
        if(a[i] == 0) continue;
        if(s > 0){
            s--;
            a[i]--;
        }else if(t > 0){
            t--;
            a[i]--;
        }else if(u > 0){
            u--;
            a[i]--;
        }
    }
    for(int i=0;i<k;i++){
        if(a[i] == 0) continue;
        if(s > 0){
            s--;
            a[i]--;
        }else if(t > 0){
            t--;
            a[i]--;
        }else if(u > 0){
            u--;
            a[i]--;
        }
    }
    for(int i=0;i<k;i++){
        if(a[i] > 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
