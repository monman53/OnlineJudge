// includes, macros {{{
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
 
typedef long long ll;
typedef unsigned long long ull; // }}}

int main(){
    int n, q;
    cin >> n >> q;
    int a[n];
    memset(a, 0, sizeof a);
    rep(i, q){
        int l, r, t;
        cin >> l >> r >> t;
        for(int j=l-1;j<r;j++){
            a[j] = t;
        }
    }
    rep(i, n){
        cout << a[i] << endl;
    }
}
