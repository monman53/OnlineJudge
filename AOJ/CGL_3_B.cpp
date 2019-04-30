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
typedef vector<P> PL;

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

// 直交判定
// verified AOJ CGL_2_A
bool orthogonalLL(P a1, P a2, P b1, P b2) {
    return EQ(dot(a1-a2, b1-b2), 0.0);
}

// 平行判定
// verified AOJ CGL_2_A
bool parallelLL(P a1, P a2, P b1, P b2) {
    return EQ(cross(a1-a2, b1-b2), 0.0);
}

// 線分と線分の交差判定
// verified AOJ CGL_2_B
bool intersectedSS(P a1, P a2, P b1, P b2) {
    return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
           ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 直線と直線の交点
// verified AOJ CGL_2_C
P intersectionLL(P a1, P a2, P b1, P b2) {
    P a = a2 - a1;
    P b = b2 - b1;
    return a1 + a*cross(b, b1-a1)/cross(b, a);
}

// 直線と点の距離
double distLP(P a, P b, P p) {
    return abs(cross(b-a, p-a)) / abs(b-a);
}

// 線分と点の距離
double distSP(P a, P b, P p) {
    if(dot(b-a, p-a) < EPS) return abs(p-a);
    if(dot(a-b, p-b) < EPS) return abs(p-b);
    return distLP(a, b, p);
}

// 線分と線分の距離
// verified AOJ CGL_2_D
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

// ポリゴンの面積 (点は半時計回り)
// verified AOJ CGL_3_A
double area(PL pl) {
    double ret = 0;
    int n = pl.size();
    for(int i=0;i<n;i++){
        ret += cross(pl[i], pl[(i+1)%n]);
    }
    return ret / 2.0;
}

// 凸多角形判定 (点は半時計回り)
// verified AOJ CGL_3_B
bool convex(PL pl) {
    int n = pl.size();
    for(int i=0;i<n;i++){
        if(ccw(pl[i], pl[(i+1)%n], pl[(i+2)%n]) == -1){
            return false;
        }
    }
    return true;
}

// }}}


int main() {
    double x, y;
    PL pl;

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;  P p(x, y);
        pl.push_back(p);
    }
    if(convex(pl)){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}

