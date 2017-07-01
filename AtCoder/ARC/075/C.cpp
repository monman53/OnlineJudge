// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
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

#define kita            cout << "kita\n"
#define print2(i, n)    cout << (i) << ": " << (n) << endl
#define print3(i, j, n)     cout << "(" << (i) << ", " << (j) << ") : " << (n) << endl
#define print4(i, j, n, m)  cout << "(" << (i) << ", " << (j) << ") : " << (n) << ", " << (m) << endl
#define print_mat(mat, h, w) for(int i=0;i<(h);i++){for(int j=0;j<(w);j++){cout << mat[i][j] << " ";}cout << endl;}

#define EPS (1e-10)
#define EQ(a, b) (fabs((a)-(b)) < eps)

typedef long long ll;
typedef unsigned long long ull;
// }}}


int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    int ans = 0;
    for(auto &ss : s){
        cin >> ss;
        ans += ss;
    }

    sort(s.begin(), s.end());

    if(ans%10 != 0){
        for(auto ss : s){
            if(ss%10 != 0){
                ans -= ss;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
