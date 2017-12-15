// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}
// 2d geometry {{{
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

typedef complex<double> P;
typedef vector<P> PL;

namespace std {
    bool  operator < (P a, P b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
        //return imag(a) != imag(b) ? imag(a) < imag(b) : real(a) < real(b);
    }
}

// 長さ
// double length = abs(a);

// 偏角
// double theta = arg(a);

// 単位ベクトル
// P n = a/abs(a);

// 法線ベクトル
// P n1 = a*P(0, 1);
// P n2 = a*P(0, -1);

// ヘロンの公式
double heron(double a, double b, double c) {
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

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

// ccw
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

// 多角形間距離(点，線分も多角形とするのでより一般的な距離)
// p2の頂点がp1に内包する場合は0
// O(V1*V2)
// verified AOJ2827 凸多角形柱工業都市
double distPLPL(PL p1, PL p2) {
    if(int(p1.size()) < int(p2.size())) swap(p1, p2);
    int n1 = p1.size();
    int n2 = p2.size();

    if(n1 == 1) return abs(p2[0]-p1[0]);
    if(n1 == 2){
        if(n2 == 1) return distSP(p1[0], p1[1], p2[0]);
        if(n2 == 2) return distSS(p1[0], p1[1], p2[0], p2[1]);
    }

    // n1 > 2
    for(int i=0;i<n2;i++){
        // 内包した場合を距離0としない時は，この処理をとばす．
        if(isContain(p1, p2[i])) return 0.0;
    }

    double d = abs(p2[0]-p1[0]);
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(n2 == 1){
                d = min(d, distSP(p1[i], p1[(i+1)%n1], p2[j]));
            }else{
                d = min(d, distSS(p1[i], p1[(i+1)%n1], p2[j], p2[(j+1)%n2]));
            }
        }
    }
    return d;
}

// 円の交差判定
// verified AOJ CGL_7_A
int intersectCC(P c1, double r1, P c2, double r2) {
    if(r1 < r2){
        swap(c1, c2);
        swap(r1, r2);
    }
    double dc = abs(c2-c1);
    if(dc > r1+r2)      return 4; // 共通接線の数が4(離れている)
    if(EQ(dc, r1+r2))   return 3; // 共通接線の数が3(外接している)
    if(dc+r2 > r1)      return 2; // 共通接線の数が2(交わる)
    if(EQ(dc+r2, r1))   return 1; // 共通接線の数が1(内接する)
    return 0; // 共通接線の数が0(内包する)
}

// 円と直線の交点(必ず交点を持つ場合)
// verified AOJ CGL_7_D
pair<P, P> intersectionCL(P c, double r, P s, P t) {
    double d = distLP(s, t, c);
    P p = projectionLP(s, t, c);
    P n = (s-t)/abs(s-t);
    double l = sqrt(r*r-d*d);
    return {p+l*n, p-l*n};
}

// }}}

int main() {
    std::ios::sync_with_stdio(false);
    double cx, cy, r;cin >> cx >> cy >> r;
    int q;cin >> q;
    for(int i=0;i<q;i++){
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        auto ans = intersectionCL(P{cx, cy}, r, P{x1, y1}, P{x2, y2});
        if(!(ans.first < ans.second)) swap(ans.first, ans.second);
        printf("%.8f %.8f %.8f %.8f\n", ans.first.real(), ans.first.imag(), ans.second.real(), ans.second.imag());
    }
    return 0;
}
