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
    int n, k;
    cin >> n >> k;
    ull sum[n+1];
    memset(sum, 0, sizeof(sum));
    rep(i, n){
        int a;
        cin >> a;
        sum[i+1] = sum[i] + a;
    }
    ull ans = 0;
    for(int i=k;i<n+1;i++){
        ans += sum[i] - sum[i-k];
    }
    cout << ans << endl;
}
