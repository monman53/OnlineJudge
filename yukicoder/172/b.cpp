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
    vector<int> count(13, 0);
    string s;cin >> s;
    for(int i=0;i<13;i++){
        if(s[i] > 'm'){
            cout << "Impossible" << endl;
            return 0;
        }
        count[s[i]-'a']++;
    }
    int ccount = 0;
    int count0 = 0;
    for(int i=0;i<13;i++){
        if(count[i] > 2){
            cout << "Impossible" << endl;
            return 0;
        }
        if(count[i] == 2){
            ccount++;
        }
        if(count[i] == 0){
            count0++;
        }
    }
    if(ccount > 1 || count0 > 1){
        cout << "Impossible" << endl;
        return 0;
    }
    if(ccount == 1){
        for(int i=0;i<13;i++){
            if(count[i] == 0){
                cout << char('a'+i) << endl;
                return 0;
            }
        }
    }
    for(int i=0;i<13;i++){
        cout << char('a'+i) << endl;
    }
    return 0;
}
