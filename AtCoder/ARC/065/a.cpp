// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
#define INF         1000000005

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    string words[] = {"dreamer", "dream", "eraser", "erase"};

    string s;cin >> s;

    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;

    for(int i=0;i<n;i++){
        if(dp[i]){
            for(auto w : words){
                if(i+w.size() < n+1){
                    if(s.compare(i, w.size(), w) == 0){
                        dp[i+w.size()] = true;
                    }
                }
            }
        }
    }

    cout << (dp[n] ? "YES" : "NO") << endl;

    return 0;
}
