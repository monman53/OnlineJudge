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

typedef long long ll;
typedef unsigned long long ull;
// }}}
// 2d geometry {{{

typedef complex<double> P;
typedef vector<P> PL;

namespace std {
    bool  operator < (P a, P b) {
        // return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
        return imag(a) != imag(b) ? imag(a) < imag(b) : real(a) < real(b);
    }
}

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
bool isOrthogonalLL(P a1, P a2, P b1, P b2) {
    return EQ(dot(a1-a2, b1-b2), 0.0);
}

// 平行判定
// verified AOJ CGL_2_A
bool isParallelLL(P a1, P a2, P b1, P b2) {
    return EQ(cross(a1-a2, b1-b2), 0.0);
}

// 線分と線分の交差判定
// verified AOJ CGL_2_B
bool isIntersectedSS(P a1, P a2, P b1, P b2) {
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
    if(isIntersectedSS(a1, a2, b1, b2)){
        return 0;
    }
    return min({
            distSP(a1, a2, b1),
            distSP(a1, a2, b2),
            distSP(b1, b2, a1),
            distSP(b1, b2, a2),
            });
}

// 多角形の面積 (点は半時計回り)
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
bool isConvex(PL pl) {
    int n = pl.size();
    for(int i=0;i<n;i++){
        if(ccw(pl[i], pl[(i+1)%n], pl[(i+2)%n]) == -1){
            return false;
        }
    }
    return true;
}

// 点の多角形内外判定 (点は半時計回り)
// verified AOJ CGL_3_C
int isContain(PL pl, P p) {
    bool flag = false;
    int n = pl.size();
    for(int i=0;i<n;i++){
        P a = pl[i] - p;
        P b = pl[(i+1)%n] - p;
        if(imag(a) > imag(b)) swap(a, b);
        if(imag(a) <= 0 && 0 < imag(b)){
            if(cross(a, b) < 0) flag = !flag;
        }
        if(cross(a, b) == 0 && dot(a, b) <= 0){
            return 1;       // on segment
        }
    }
    return flag ? 2 : 0;    // in or out
}

// 凸包 (plは点集合)
// verified AOJ CGL_4_A
PL convexHull(PL pl){
    int n = pl.size();
    int k = 0;
    PL ch(2*n); // results
    sort(pl.begin(), pl.end()); // この順序は問題に依る
    for(int i=0;i<n;ch[k++]=pl[i++]){
        while(k >= 2 && (ccw(ch[k-2], ch[k-1], pl[i]) == 0 ||
                         ccw(ch[k-2], ch[k-1], pl[i]) == -1)) k--;
    }
    for(int i=n-2,t=k+1;i>=0;ch[k++]=pl[i--]){
        while(k >= t && (ccw(ch[k-2], ch[k-1], pl[i]) == 0 ||
                         ccw(ch[k-2], ch[k-1], pl[i]) == -1)) k--;
    }
    ch.resize(k-1);
    return ch;
}

// }}}

int INF = 1000000005;
int n[2];
P p[2][1005];
double cost[2][1005];

typedef pair<double, int> V;

int main() {
    cin >> n[0] >> n[1];
    for(int i=0;i<2;i++){
        for(int j=0;j<n[i];j++){
            double x, y;cin >> x >> y;
            p[i][j] = {x, y};
            cost[i][j] = INF;
        }
    }

    double ans = INF;

    for(int ab=0;ab<2;ab++){
        priority_queue<V, vector<V>, greater<V>> pq;
        pq.push({0.0, 0});
        while(!pq.empty()){
            auto cv = pq.top();
            pq.pop();
            double ccost = cv.first;
            int ci = cv.second;

            if(ccost >= cost[ab][ci]){
                continue;
            }
            cost[ab][ci] = ccost;

            P cp = p[ab][ci];
            for(int ni=0;ni<n[ab];ni++){
                if(ni != ci){
                    P np = p[ab][ni];
                    if(!EQ(distSS(cp, np, p[(ab+1)%2][0], p[(ab+1)%2][1]), 0.0)){
                        double ncost = ccost + abs(np - cp);
                        pq.push({ncost, ni});
                    }
                }
            }
        }

        if(cost[ab][1] != INF){
            ans = min(ans, abs(p[(ab+1)%2][1] - p[(ab+1)%2][0]) + cost[ab][1]);
        }
    }

    if(ans == INF){
        printf("%d\n", -1);
    }else{
        printf("%0.12lf\n", ans);
    }

    return 0;
}
