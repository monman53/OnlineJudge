#include <iostream>
#include <cstdio>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
using namespace std;

class Point{
  public:
  double x, y;
  Point(double x=0, double y=0): x(x), y(y){}
  Point operator - (Point p) {return Point(x-p.x, y-p.y);}
};
typedef Point Vector;

class Segment{
  public:
  Point p1, p2;
  Segment(Point p1, Point p2): p1(p1), p2(p2){}
};
typedef Segment Line;

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

double getDistanceLP(Line l, Point p){
  return abs(cross(l.p2-l.p1, p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s, Point p){
  if(dot(s.p2 - s.p1, p-s.p1) < 0.0) return abs(p - s.p1);
  if(dot(s.p1 - s.p2, p-s.p2) < 0.0) return abs(p - s.p2);
  return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2){
  return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
             min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

int main(){
  int n_ue, n_shita;
  double x, y, bx, by;
  vector<Segment> ue;
  vector<Segment> shita;

  bx = 0;
  by = 0;
  cin >> n_shita;
  for(int i=0;i<n_shita;i++){
    cin >> x >> y;
    shita.push_back(Segment(Point(bx, by), Point(x, y)));
    bx = x;
    by = y;
  }
  shita.push_back(Segment(Point(bx, by), Point(1000, 0)));
  
  bx = 0;
  by = 1000;
  cin >> n_ue;
  for(int i=0;i<n_ue;i++){
    cin >> x >> y;
    ue.push_back(Segment(Point(bx, by), Point(x, y)));
    bx = x;
    by = y;
  }
  ue.push_back(Segment(Point(bx, by), Point(1000, 1000)));

  double ans = 1000;
  
  for(int i=0;i<(int)ue.size();i++){
    for(int j=0;j<(int)shita.size();j++){
      ans = min(ans, getDistance(ue[i], shita[j]));
    }
  }

  printf("%.9f\n", ans);
  
  return 0;
}
