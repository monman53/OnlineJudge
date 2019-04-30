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
#include <cstring>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
// #define EQ(a, b)    (abs((a)-(b)) < EPS)
inline bool EQ(double a, double b) {return abs(a-b) < EPS;}
// ciling(x/y) = (x+y-1)/y

// template<class T>
// using P = pair<T, T>;
using ll  = long long;
using ull = unsigned long long;
// }}}

int main() {
    string s1, s2;cin >> s1 >> s2;
    string s;cin >> s;
    for(auto c : s){
        if('a' <= c && c <= 'z'){
            for(int i=0;i<ALPHABET;i++){
                if(s1[i]-'a' == c-'a'){
                    cout << s2[i];
                    break;
                }
            }
        }else if('A' <= c && c <= 'Z'){
            for(int i=0;i<ALPHABET;i++){
                if(s1[i]-'a' == c-'A'){
                    cout << char(s2[i]-('a'-'A'));
                    break;
                }
            }
        }else{
            cout << c;
        }
    }
    cout << endl;
    return 0;
}
