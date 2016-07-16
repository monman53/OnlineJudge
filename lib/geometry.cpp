// 平面幾何ライブラリ(※整理後未検証2016-07-16)
#include "includes.cpp"

// Point(Vector)
//  Point(double x = 0, double y = 0)   点を作成する
//  double norm()                       x*x + y*yを返す
//  double abs()                        原点からの距離を返す
//  
// depends on
// 
class Point;    // {{{
typedef Point Vector;
class Point{
public:
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y){}

    Point operator + (Point p){return Point(x+p.x, y+p.y);}
    Point operator - (Point p){return Point(x-p.x, y-p.y);}
    Point operator * (double a){return Point(x*a, y*a);}
    Point operator / (double a){return Point(x/a, y/a);}

    // ノルム
    double norm(){return x*x+y*y;}
    static double norm(Vector a){return a.x*a.x+a.y*a.y;}
    // 大きさ
    double abs(){return sqrt(norm());}
    static double abs(Vector a){return sqrt(a.norm());}
    // 内積
    static double dot(Vector a, Vector b){return a.x*b.x + a.y*b.y;}
    // 外積
    static double cross(Vector a, Vector b){return a.x*b.y - a.y*b.x;}
    // 直交判定
    static bool isOrthogonal(Vector a, Vector b){return equals(Point::dot(a, b), 0.0);}
    // 並行判定
    static bool isParallel(Vector a, Vector b){return equals(Point::cross(a, b), 0.0);}
    

    static const int COUNTER_CLOCKWISE = 1;
    static const int CLOCKWISE = -1;
    static const int ONLINE_BACK = 2;
    static const int ONLINE_FRONT = -2;
    static const int ON_SEGMENT = 0;
    static int ccw(Point p0, Point p1, Point p2){
        Vector a = p1 - p0;
        Vector b = p2 - p0;
        if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
        if(cross(a, b) < -EPS) return CLOCKWISE;
        if(dot(a, b) < -EPS) return ONLINE_BACK;
        if(a.norm() < b.norm()) return ONLINE_FRONT;
        return ON_SEGMENT;
    }

    static bool intersect(Point p1, Point p2, Point p3, Point p4){
        return (ccw(p1, p2, p3)*ccw(p1, p2, p4) <= 0 &&
                ccw(p3, p4, p1)*ccw(p3, p4, p2) <= 0);
    }
    
    static double getDistance(Point a, Point b){
        return abs(a-b);
    }

    bool operator < (const Point &p) const {return (!equals(x, p.x) ? x < p.x : y < p.y);}
    bool operator == (const Point &p) const {return equals(x, p.x) && equals(y, p.y);}
};  //  }}}

// Segment(Line)
//  Segment(Point p1 = Point(), Point p2 = Point())     二点から線分(直線)を作成する
//  double norm()                                       線分のノルムを計算する
//  double abs()                                        線分の長さを計算する
//  Vector vect()                                       p1を基準としたベクトルに変換する
//  
// depends on
//  Point
//
class Segment;  // {{{
typedef Segment Line;
class Segment{
public:
    Point p1, p2;
    Segment(Point p1 = Point(), Point p2 = Point()): p1(p1), p2(p2){}

    double norm(){return (p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);}
    double abs(){return sqrt(norm());}
    Vector vct(){return p2-p1;}

    Point project(Point p){
       Vector base = this->vct();
       double r = Point::dot(p - this->p1, base)/base.norm();
       return this->p1+base*r;
    }
    Point reflect(Point p){
        return p + (this->project(p) - p)*2.0;
    }
    
    static bool intersect(Segment s1, Segment s2){
        return Point::intersect(s1.p1, s1.p2, s2.p1, s2.p2);
    }

    static double getDistanceLP(Line l, Point p){
        return std::abs(Point::cross(l.p2-l.p1, p-l.p1)/Point::abs(l.p2-l.p1));
    }

    static double getDistanceSP(Segment s, Point p){
        if(Point::dot(s.p2-s.p1, p-s.p1) < 0.0) return Point::abs(p-s.p1);
        if(Point::dot(s.p1-s.p2, p-s.p2) < 0.0) return Point::abs(p-s.p2);
        return getDistanceLP(s, p);
    }

    static double getDistance(Segment s1, Segment s2){
        if(intersect(s1, s2)) return 0.0;
        return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
                min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
    }
};  // }}}

// Circle
//  Circle(Point c = Point(), double r = 0.0)   中心と半径から円を作成する
// depends on
//  Point
class Circle{   // {{{
public:
    Point c;
    double r;

    Circle(Point c = Point(), double r = 0.0): c(c), r(r){}
};  // }}}
   
typedef vector<Point> Polygon;
