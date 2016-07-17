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
    ll t, s, x;

    cin >> t >> s >> x;

    if(x < t){
        cout << "NO" << endl;
        return 0;
    }

    if(t == x){
        cout << "YES" << endl;
        return 0;
    }

    if((x-t)%s == 0 && double((x-t))/double(s) > 0){
        cout << "YES" << endl;
        return 0;
    }
    
    if((x-t-1)%s == 0 && double((x-t-1))/double(s) > 0){
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}
