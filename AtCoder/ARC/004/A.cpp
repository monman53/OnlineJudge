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
    vector<pair<double, double>> data(n, {0, 0});
    for(auto &p : data){
        cin >> p.first >> p.second;
    }

    double ans = 0;

    for(auto p1 : data){
        for(auto p2 : data){
            double dx = p2.first - p1.first;
            double dy = p2.second - p1.second;
            double l  = sqrt(dx*dx + dy*dy);

            ans = max(ans, l);
        }
    }

    cout << ans << endl;
    return 0;
}
