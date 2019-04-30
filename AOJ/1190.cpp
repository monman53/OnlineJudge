#include <bits/stdc++.h>
using namespace std;

#define EPS         (1e-7)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

typedef complex<double> P;

// ヘロンの公式
double heron(double a, double b, double c) {
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

struct D {
    P p;
    double l;
};

bool check1(const D &a, const D &b, const D &c) {
    double al = a.l;
    double bl = b.l;
    double cl = c.l;
    double ab = abs(b.p - a.p);
    double ca = abs(a.p - c.p);
    return al*al + ab*ab <= bl*bl && al*al + ca*ca <= cl*cl;
}

bool check2(const D &a, const D &b, const D &c) {
    double al = a.l;
    double bl = b.l;
    double cl = c.l;
    double ab = abs(b.p - a.p);
    if(al*al + ab*ab >= bl*bl && bl*bl + ab*ab >= al*al){
        double abh = heron(ab, al, bl)*2.0/ab;
        double aa = sqrt(al*al-abh*abh);
        double bb = sqrt(bl*bl-abh*abh);
        P abm = a.p + (aa/(aa+bb))*(b.p-a.p);
        double d = abs(abm-c.p);
        if(abh*abh + d*d <= cl*cl){
            return true;
        }
    }
    return false;
}

double solve(const D &a, const D &b, const D &c) {
    double al = a.l;
    double bl = b.l;
    double cl = c.l;
    double ab = abs(b.p - a.p);
    double bc = abs(c.p - b.p);
    double ca = abs(a.p - c.p);
    double abh = heron(ab, al, bl)*2.0/ab;
    double bch = heron(bc, bl, cl)*2.0/bc;
    double cah = heron(ca, cl, al)*2.0/ca;

    // 1
    if(check1(a, b, c)) return al;
    if(check1(b, c, a)) return bl;
    if(check1(c, a, b)) return cl;

    // 2
    if(check2(a, b, c)) return abh;
    if(check2(b, c, a)) return bch;
    if(check2(c, a, b)) return cah;

    // 3
    double xa = a.p.real();
    double ya = a.p.imag();
    double xb = b.p.real();
    double yb = b.p.imag();
    double xc = c.p.real();
    double yc = c.p.imag();
    double aa = -xa+xb;
    double bb = -ya+yb;
    double cc = -xb+xc;
    double dd = -yb+yc;
    double p  = (al*al-bl*bl-xa*xa-ya*ya+xb*xb+yb*yb)/2;
    double q  = (bl*bl-cl*cl-xb*xb-yb*yb+xc*xc+yc*yc)/2;
    double x = (dd*p-bb*q)/(aa*dd-bb*cc);
    double y = (aa*q-cc*p)/(aa*dd-bb*cc);
    if(EQ(aa*dd-bb*cc, 0.0)) return 10000;
    double ret = sqrt(al*al - (x-xa)*(x-xa) - (y-ya)*(y-ya));
    return ret;
}

int main() {
    while(true){
        int n;cin >> n;
        if(n == 0) break;
        vector<D> d(n);
        for(int i=0;i<n;i++){
            double x, y, l;cin >> x >> y >> l;
            d[i] = {{x, y}, l};
        }
        d.push_back({{0, 400}, 10000});
        d.push_back({{400, 0}, 10000});
        sort(d.begin(), d.end(), [](D l, D r){return l.l < r.l;});
        double ans = 500;
        for(int i=0;i<n+2;i++){
            for(int j=0;j<n+2;j++){
                for(int k=0;k<n+2;k++){
                    if(i == j || j == k || k == i) continue;
                    ans = min(ans, solve(d[i], d[j], d[k]));
                }
            }
        }
        printf("%.6lf\n", ans);
    }

    return 0;
}
