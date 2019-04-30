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
    int n;cin >> n;
    stack<string> st;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        if(s == "A"){
            st.push(s);
        }else{
            if(st.size() > 0){
                st.pop();
            }else{
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if(st.size() > 0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}
