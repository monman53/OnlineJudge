#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
using namespace std;

class Point;
typedef Point Vector;
class Segment;
typedef Segment Line;
double norm(Vector a);
double abs(Vector a);
double dot(Vector a, Vector b);
double cross(Vector a, Vector b);
bool isOrthogonal(Vector a, Vector b);
bool isParallel(Vector a, Vector b);
Point project(Segment s, Point p);
Point reflect(Segment s, Point p);
int ccw(Point p0, Point p1, Point p2);
bool intersect(Point p1, Point p2, Point p3, Point p4);
bool intersect(Segment s1, Segment s2);
double getDistance(Point a, Point b);
double getDistanceLP(Line l, Point p);
double getDistanceSP(Segment s, Point p);
double getDistance(Segment s1, Segment s2);

class Point{
public:
  double x, y;
  Point(double x = 0, double y = 0): x(x), y(y){}

  Point operator + (Point p){return Point(x+p.x, y+p.y);}
  Point operator - (Point p){return Point(x-p.x, y-p.y);}
  Point operator * (double a){return Point(x*a, y*a);}
  Point operator / (double a){return Point(x/a, y/a);}

  double norm(){return x*x+y*y;}
  double abs(){return sqrt(norm());}

  bool operator < (const Point &p) const {return (!equals(x, p.x) ? x < p.x : y < p.y);}
  bool operator == (const Point &p) const {return equals(x, p.x) && equals(y, p.y);}
};

class Segment{
public:
  Point p1, p2;
  Segment(Point p1 = Point(), Point p2 = Point()): p1(p1), p2(p2){}
  
  double norm(){return (p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);}
  double abs(){return sqrt(norm());}
  Vector vct(){return p2-p1;}
};

double INF = 1 << 30;

int main(){
  while(1){
    int n, m, l;
    cin >> n >> m >> l;
    if(n == 0 && m == 0 && l == 0) break;
    vector<vector<Segment>> data;
    
    for(int i=0;i<n;i++){
      double x, y, a, r;
      vector<Point> point;
      cin >> x >> y >> a >> r;
      for(int j=0;j<5;j++){
        double rad = 2.0*M_PI*(j/5.0 + a/360.0);
        point.push_back(Point(x - r*sin(rad), y + r*cos(rad)));
      }
      vector<Segment> segment;
      for(int j=0;j<5;j++){
        segment.push_back(Segment(point[j], point[(j+2)%5]));
      }
      data.push_back(segment);
    }
    vector<vector<double>> dp(n, vector<double>(n, INF));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        for(int k=0;k<5;k++){
          for(int o=0;o<5;o++){
            dp[i][j] = min(dp[i][j], getDistance(data[i][k], data[j][o]));
          }
        }
      }
    }
    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }

    printf("%f\n", dp[m-1][l-1]);
  }
  return 0;
}


double norm(Vector a){
  return a.x*a.x + a.y*a.y;
}

double abs(Vector a){
  return sqrt(norm(a));
}

double dot(Vector a, Vector b){
  return a.x*b.x + a.y*b.y;
}

double cross(Vector a, Vector b){
  return a.x*b.y - a.y*b.x;
}

bool isOrthogonal(Vector a, Vector b){
  return equals(dot(a, b), 0.0);
}

bool isParallel(Vector a, Vector b){
  return equals(cross(a, b), 0.0);
}

Point project(Segment s, Point p){
  Vector base = s.vct();
  double r = dot(p - s.p1, base)/norm(base);
  return s.p1+base*r;
}

Point reflect(Segment s, Point p){
  return p + (project(s, p) - p)*2.0;
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
int ccw(Point p0, Point p1, Point p2){
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if(cross(a, b) < -EPS) return CLOCKWISE;
  if(dot(a, b) < -EPS) return ONLINE_BACK;
  if(a.norm() < b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool intersect(Point p1, Point p2, Point p3, Point p4){
  return (ccw(p1, p2, p3)*ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1)*ccw(p3, p4, p2) <= 0);
}
bool intersect(Segment s1, Segment s2){
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double getDistance(Point a, Point b){
  return abs(a-b);
}

double getDistanceLP(Line l, Point p){
  return abs(cross(l.p2-l.p1, p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s, Point p){
  if(dot(s.p2-s.p1, p-s.p1) < 0.0) return abs(p-s.p1);
  if(dot(s.p1-s.p2, p-s.p2) < 0.0) return abs(p-s.p2);
  return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2){
  if(intersect(s1, s2)) return 0.0;
  return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
             min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}
