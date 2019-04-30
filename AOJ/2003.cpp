#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
using namespace std;
#define EPS (1e-9)

typedef complex<double> P;

double cross(P a, P b){
  return (a.real()*b.imag() - a.imag()*b.real());
}

bool is_intersected(P a1, P a2, P b1, P b2){
  return ((cross(a2-a1, b1-a1)*cross(a2-a1, b2-a1) < EPS) &&
          (cross(b2-b1, a1-b1)*cross(b2-b1, a2-b1) < EPS));
}

struct Data{
  double d;
  int l;
  Data(double x, int y){
    d = x;
    l = y;
  }
  bool operator<(const Data &a) const{
    return d < a.d;
  }
};

int main(){
  int m;
  cin >> m;
  for(int i=0;i<m;i++){
    P a, b;
    int n;
    vector<Data> data;
    cin >> a.real() >> a.imag();
    cin >> b.real() >> b.imag();
    cin >> n;
    for(int j=0;j<n;j++){
      P s, t;
      int o, l;
      cin >> s.real() >> s.imag();
      cin >> t.real() >> t.imag();
      cin >> o >> l;
      if(!is_intersected(a, b, s, t)) continue;
      if(abs(cross(b-a, t-s)) < EPS) continue;

      P x = t-s;
      double d1 = abs(cross(x, a-s));
      double d2 = abs(cross(x, b-s));
      double d = d1/(d1+d2);
      if(o == 1){
        l = l;   
      }else{
        l = 1-l;
      }
      data.push_back(Data(d, l));
    }
    sort(data.begin(), data.end());
    int count = 0;
    int before;
    if(data.size()){
      before = data[0].l;
    }
    for(int j=1;j<(int)data.size();j++){
      if(data[j].l != before){
        count++;
        before = data[j].l;
      }
    }
    cout << count << '\n';
  }
}
