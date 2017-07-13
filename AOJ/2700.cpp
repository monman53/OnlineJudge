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

string code(string s, int l){
    string ret = "";
    ret.push_back(s[0]);
    int n = s.size();
    for(int i=0;i<n;i++){
        char c = s[i];
        if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
            if(i+1 < n){
                ret.push_back(s[i+1]);
            }
        }
    }
    if(ret.size() > l){
        return ret.substr(0, l);
    }else{
        return ret;
    }
}

int main() {
    while(true){
        int n;cin >> n;
        if(n == 0) break;

        vector<string> v(n);
        int maxlen = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            maxlen = max(maxlen, int(v[i].size()));
        }


        bool flag = false;
        for(int l=1;l<=maxlen;l++){
            set<string> st;
            for(int i=0;i<n;i++){
                string ss = code(v[i], l);
                st.insert(ss);
            }
            if(st.size() == n){
                cout << l << endl;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << -1 << endl;
        }
    }
    return 0;
}
