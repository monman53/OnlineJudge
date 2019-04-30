// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

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

// 直線と線分の距離
// あやしい
double distLS(P l1, P l2, P s1, P s2){
    P p = intersectionLL(l1, l2, s1, s2);
    if(ccw(s1, s2, p) == 0){
        return 0.0;
    }else{
        return min(distLP(l1, l2, s1), distLP(l1, l2, s2));
    }
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

// 凸多角形の直径(最遠頂点対間距離)
// キャリパー法 O(n)
// verified AOJ CGL_4_B (理解できてない)
double diameterOfConvex(PL pl) {
    int n = pl.size();
    int is = 0;
    int js = 0;
    for(int i=1;i<n;i++){
        if(pl[i].imag() > pl[is].imag()) is = i;
        if(pl[i].imag() < pl[js].imag()) js = i;
    }
    double maxd = norm(pl[is]-pl[js]);

    int i, maxi, j, maxj;
    i = maxi = is;
    j = maxj = js;
    do{
        if(cross(pl[(i+1)%n]-pl[i], pl[(j+1)%n]-pl[j]) >= 0){
            j = (j+1)%n;
        }else{
            i = (i+1)%n;
        }
        if(norm(pl[i]-pl[j]) > maxd){
            maxd = norm(pl[i]-pl[j]);
            maxi = i;
            maxj = j;
        }
    }while(i != is || j != js);
    return sqrt(maxd);
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

// 円と円の交点(必ず交点を持つ場合)
// verified AOJ CGL_7_E
pair<P, P> intersectionCC(P c1, double r1, P c2, double r2) {
    if(r1 < r2){
        swap(c1, c2);
        swap(r1, r2);
    }
    double d = abs(c2-c1);
    P n = (c2-c1)/abs(c2-c1);
    double theta = acos((d*d+r1*r1-r2*r2)/(2.0*d*r1));
    return {c1+r1*n*P{cos(theta), sin(theta)}, c1+r1*n*P{cos(-theta), sin(-theta)}};
}

// 点pを通る円cとの接線(その接点2つを返す)
// verified AOJ CGL_7_F
pair<P, P> tangentCP(P c, double r, P p) {
    double d = abs(p-c);
    double l = sqrt(d*d-r*r);
    P n = (c-p)/abs(c-p);
    double theta = atan2(r, l);
    return {p+l*n*P{cos(theta), sin(theta)}, p+l*n*P{cos(-theta), sin(-theta)}};
}

// }}}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    double X, Y; cin >> X >> Y;
    double R; cin >> R;
    double SX, SY; cin >> SX >> SY;
    int k;cin >> k;

    const double pi = acos(-1);

    P C(X, Y);
    P S(SX, SY);

    auto os = intersectionCL(P(0, 0), 1, S, C);

    //cout << os.fi << endl; 
    //cout << os.se << endl;
    P o = os.fi;
    //cout << o << endl;

    auto ray = tangentCP(C, R, S);
    P ray1 = intersectionCL(P(0, 0), 1, S, ray.fi).se;
    P ray2 = intersectionCL(P(0, 0), 1, S, ray.se).se;

    //cout << ray1 << endl;
    //cout << ray2 << endl;

    double ans1 = 0;
    double ans2 = 0;
    bool fin1 = false;
    bool fin2 = false;

    auto fi1 = ray1;
    auto fi2 = ray2;

    for(int t=0;t<=k;t++){
        //cout << ray1 << " " << ray2 << endl;
        double ans1 = acos(dot(o, ray1)/(abs(o)*abs(ray1)));
        double ans2 = acos(dot(o, ray2)/(abs(o)*abs(ray2)));

        if(cross(o, fi1)*cross(o, ray1) <= 0){
            fin1 = true;
        }
        if(cross(o, fi2)*cross(o, ray2) <= 0){
            fin2 = true;
        }

        if(fin1){
            ans1 = pi;
        }

        if(fin2){
            ans2 = pi;
        }

        printf("%.9lf\n", min((ans1+ans2)/(2*pi), 1.0));

        auto ray11 = tangentCP(C, R, ray1);
        auto ray22 = tangentCP(C, R, ray2);
        ray1 = intersectionCL(P(0, 0), 1, ray1, ray11.fi).se;
        ray2 = intersectionCL(P(0, 0), 1, ray2, ray22.se).se;
    }
    return 0;
}
