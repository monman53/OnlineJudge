// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
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
#define EQ(a, b) (abs((a)-(b)) < EPS)

typedef long long ll;
typedef unsigned long long ull;
// }}}

// 2d geometry {{{

typedef complex<double> P;
typedef vector<P> L;

// 長さ
// double length = abs(a);

// 単位ベクトル
// P n = a/abs(a);

// 法線ベクトル
// P n1 = a*P(0, 1);
// P n2 = a*P(0, -1);

// 内積
double dot(P a, P b) {
    return a.real()*b.real() + a.imag()*b.imag();
}

// 外積
double cross(P a, P b) {
    return a.real()*b.imag() - a.imag()*b.real();
}

// 直交判定
bool orthogonalLL(P a1, P a2, P b1, P b2) {
    return EQ(dot(a1-a2, b1-b2), 0.0);
}

// 平行判定
bool parallelLL(P a1, P a2, P b1, P b2) {
    return EQ(cross(a1-a2, b1-b2), 0.0);
}

// verified AOJ CGL_1_C
int ccw(P a, P b, P c) {
    b = b - a;
    c = c - a;
    if(cross(b, c) > EPS) return +1; // counter clockwise
    if(cross(b, c) <-EPS) return -1; // clockwise
    if(dot(b, c) < 0)     return +2; // cab (back)
    if(abs(b) < abs(c))   return -2; // abc (front)
    return 0;                        // acb (on segment)
}

bool intersectedSS(P a1, P a2, P b1, P b2) {
    return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
           ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

P intersectionLL(P a1, P a2, P b1, P b2) {
    P a = a2 - a1;
    P b = b2 - b1;
    return a1 + a*cross(b, b1-a1)/cross(b, a);
}

// 点の直線への射影
// verified AOJ CGL_1_A
P projectionLP(P a, P b, P p) {
    double l = dot(p-a, b-a) / norm(b-a);
    return a + l*(b-a);
}

// 点の直線に対する対称点
// verified AOJ CGL_1_B
P reflectionLP(P a, P b, P p) {
    return 2.0*projectionLP(a, b, p) - p;
}

double distLP(P a, P b, P p) {
    return abs(cross(b-a, p-a)) / abs(b-a);
}

double distSP(P a, P b, P p) {
    if(dot(b-a, p-a) < EPS) return abs(p-a);
    if(dot(a-b, p-b) < EPS) return abs(p-b);
    return distLP(a, b, p);
}

double distSS(P a1, P a2, P b1, P b2) {
    if(intersectedSS(a1, a2, b1, b2)){
        return 0;
    }
    return min({
            distSP(a1, a2, b1),
            distSP(a1, a2, b2),
            distSP(b1, b2, a1),
            distSP(b1, b2, a2),
            });
}

// // verified AOJ CGL_3_A
// double area(Polygon pl) {
//     double ret = 0;
//     int n = pl.size();
//     for(int i=0;i<n;i++){
//         ret += cross(pl[i], pl[(i+1)%n]);
//     }
//     return ret / 2.0;
// }
//
// // verified AOJ CGL_3_B
// bool is_convex(Polygon pl) {
//     int n = pl.size();
//     for(int i=0;i<n;i++){
//         int c = ccw(pl[i], pl[(i+1)%n], pl[(i+2)%n]);
//         if(c == -1){
//             return false;
//         }
//     }
//     return true;
// }

// }}}


int main() {
    double x, y;
    cin >> x >> y;
    P s(x, y);
    cin >> x >> y;
    P t(x, y);

    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> x >> y;
        P p(x, y);

        int ans = ccw(s, t, p);

        switch(ans){
            case 1:
                cout << "COUNTER_CLOCKWISE" << endl;
                break;
            case -1:
                cout << "CLOCKWISE" << endl;
                break;
            case 2:
                cout << "ONLINE_BACK" << endl;
                break;
            case -2:
                cout << "ONLINE_FRONT" << endl;
                break;
            case 0:
                cout << "ON_SEGMENT" << endl;
                break;
        }

        // printf("%0.10lf %0.10lf\n", ans.real(), ans.imag());
    }
    return 0;
}

