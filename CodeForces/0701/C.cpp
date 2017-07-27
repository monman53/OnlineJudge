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
#include <climits>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)

#define rep(i, s, e)    for (int i = (s); i < (int)(e); i++)
//#define PB(e) push_back(e)
//#define MP(a, b) make_pair(a, b)

// for debug
#define kita            cout << "kita\n"
#define print2(i, n)    cout << (i) << ": " << (n) << endl
#define print3(i, j, n)     cout << "(" << (i) << ", " << (j) << ") : " << (n) << endl
#define print4(i, j, n, m)  cout << "(" << (i) << ", " << (j) << ") : " << (n) << ", " << (m) << endl
#define print_mat(mat, h, w) for(int i=0;i<(h);i++){for(int j=0;j<(w);j++){cout << mat[i][j] << " ";}cout << endl;}
 
typedef long long ll;
typedef unsigned long long ull; // }}}

int main(){
    int n;
    string s;
    set<char> st1;
    cin >> n >> s;
    rep(i, 0, n){
        st1.insert(s[i]);
    }
    int var = int(st1.size());

    int count[2000];
    rep(i, 0, 2000){
        count[i] = 0;
    }

    set<char> st;
    int r=0, l=0;
    int ans = 200000;
    while(!(l == n && r == n)){
        if(int(st.size()) == var || r == n){
            if(int(st.size()) == var){
                ans = min(ans, r-l);
            }
            count[int(s[l]-'A')]--;
            if(count[int(s[l]-'A')] == 0){
                st.erase(st.find(s[l]), st.end());
            }
            l++;
        }else{
            st.insert(s[r]);
            count[int(s[r]-'A')]++;
            r++;
        }
    }

    r = n-1;
    l = n-1;
    
    while(!(l == -1 && r == -1)){
        if(int(st.size()) == var || l == -1){
            if(int(st.size()) == var){
                ans = min(ans, r-l);
            }
            count[int(s[r]-'A')]--;
            if(count[int(s[r]-'A')] == 0){
                st.erase(st.find(s[r]), st.end());
            }
            r--;
        }else{
            st.insert(s[l]);
            count[int(s[l]-'A')]++;
            l--;
        }
    }

    cout << ans << endl;

    return 0;
}
