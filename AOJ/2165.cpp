#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int S, A, C, M, N;
int mS, mA, mC;
int I[256];
int O[256];
int Rl[257];
double mmin;

int R(int i){
  if(i == 0){
    return (Rl[0] = S);
  }else{
    return (Rl[i] = (A*Rl[i-1]+C)%M);
  }
}

double H(){
  int count[256];
  double ret = 0;
  for(int i=0;i<256;i++){
    count[i] = 0;
  }
  for(int i=0;i<N;i++){
    count[O[i]]++;
  }
  for(int i=0;i<256;i++){
    if(count[i] != 0){
//      cout << double(log(double(count[i])))/N << endl;
      ret += -(double(count[i])/double(N))*double(log(double(count[i])/double(N)));
    }
  }
  return ret;
}

int comp(double d1, double d2){
  if(abs(d1 - d2) < 0.00000001){
    return 0;
  }else if(d1 - d2 >= 0.00000001){
    return 1;
  }else{
    return -1;
  }
}


void ans(){
  for(int i=0;i<=15;i++){
    S = i;
    for(int j=0;j<=15;j++){
      A = j;
      for(int k=0;k<=15;k++){
        C = k;
        Rl[0] = S;
        for(int l=0;l<N;l++){
          O[l] = (I[l] + R(l+1))%M;
        }
        double mmmin;
        if(i==0 && j==0 && k==0){
          mmin = H();
          mS = 0;
          mA = 0;
          mC = 0;
        }else if(comp(mmin, (mmmin = H())) > 0){
          //cout << (mmin == mmmin) << endl;
//          printf("%.20f\n", mmmin);
//          cout << S << " " << A << " " << C << endl;
          mmin = mmmin;
          mS = S;
          mA = A;
          mC = C;
        }
      }
    }
  }
}

int main(){
  M = 256;
  while(1){
    cin >> N;
    if(N==0) break;

    for(int i=0;i<N;i++){
      cin >> I[i];
    }
    ans();
    cout << mS << " " << mA << " " << mC << '\n';
  }
  return 0;
}
