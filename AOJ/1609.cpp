// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
// #include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
// ciling(x/y) = (x+y-1)/y

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    while(true){
        int n;cin >> n;
        if(n == 0) break;
        map<char, int> m;
        set<char> s;
        vector<char> v(n);
        for(auto &vv : v){
            cin >> vv;
            m[vv] = n;
            s.insert(vv);
        }
        bool flag = false;
        for(int i=0;i<n;i++){
            char c = v[i];
            for(auto &kv : m){
                kv.second--;
            }
            m[c]++;
            int last = n-i-1;
            if(s.size() == 1){
                if(n/2+1 == i+1){
                    cout << c << " " << i+1 << endl;
                    flag = true;
                    break;
                }else{
                    continue;
                }
            }
            char ans;
            for(auto &kv : m){
                char k = kv.first;
                int v = kv.second;
                int count = 0;
                for(auto &kv : m){
                    char kk = kv.first;
                    int vv = kv.second;
                    if(kk != k && v-last <= vv){
                        count++;
                    }
                }
                if(count == 0){
                    flag = true;
                    ans = k;
                    break;
                }
            }
            if(flag){
                cout << ans << " " << i+1 << endl;
                break;
            }
        }
        if(!flag){
            cout << "TIE" << endl;
        }
    }
    return 0;
}
