#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

double diff[20][20];
bool use[20];
int usepos;
double mmax;
double mmin;
int n, m;

// m <= n/2
void fmax(int m, int from){
  if(m == 0){
    double nowmax = 0;
    for(int i=0;i<n;i++){
      if(use[i]){
        for(int j=0;j<n;j++){
          if(use[j]){
            nowmax += diff[i][j];
          }
        }
      }
//      cout << use[i];
    }
    nowmax /= 2;
//    cout << " " << nowmax;
//    cout << endl;
//    cout << nowmax << endl;
//    cout << mmax << endl;
//    mmax = max(mmax, nowmax);
    if(mmax < nowmax) mmax = nowmax;
    return;
//    cout << mmax << endl;
  }
  for(int i=from;i<n;i++){
    if(!use[i]){
      use[i] = true;
      fmax(m-1, i+1);
      use[i] = false;
    }
  }
}

int main(){
  cin >> n >> m;
  double L[20], a[20], b[20];
  for(int i=0;i<n;i++){
    cin >> L[i] >> a[i] >> b[i];
  }

  mmax = 0;
  mmin = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      diff[i][j] = (L[i]-L[j])*(L[i]-L[j]) + (a[i]-a[j])*(a[i]-a[j]) + (b[i]-b[j])*(b[i]-b[j]);
//      cout << "diff[" << i << "][" << j << "] == " << diff[i][j] << endl;
      mmin += diff[i][j];
    }
  }

  usepos = 0;
  for(int i=0;i<n;i++){
    use[i] = false;
  }
  
  fmax(m, 0);
  //cout << mmax << '\n';
  printf("%f\n", mmax);

  return 0;
}
