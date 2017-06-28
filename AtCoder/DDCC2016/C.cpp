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

ll A, B, C;

string T;

int main(){
    cin >> A >> B >> C;
    cin >> T;
    
    vector<char> cl;
    vector<int> nl;

    for(int i=0;i<T.length();){
        char c = T[i];
        int count = 0;

        int j;
        for(j=i;T.length();i++){
            if(T[j] == c){
                count++;
            }else{
                i = j;
                break;
            }
            if(j == T.length() -1){
                i = T.length();
            }
        }

        cl.push_back(c);
        nl.push_back(count);
    }

    cout << ming(min(A*T.length(), B*T.length()) + C*(cl.size()-1)) << endl;
    
    return 0;
}
