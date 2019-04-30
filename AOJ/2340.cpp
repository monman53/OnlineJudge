#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

struct Seq{
  char c;
  int n;
  Seq(char x, int y){
    c = x;
    n = y;
  }
};

int main(){
  list<Seq> data;

  list<Seq>::iterator fit;
  list<Seq>::iterator bit;

  int q;
  cin >> q;

  int p, n;
  char c;

  for(int i=0;i<q;i++){
    cin >> p >> c >> n;
    if(i == 0){
      data.push_front(Seq(c, n));
    }else{
      int sum=0;
      for(fit=data.begin();fit!=data.end();fit++){
        list<Seq>::iterator nit;
        nit = fit;
        if(p == sum){
          if(fit->c == c){
            fit->n += n;
            break;
          }
          if(fit == data.begin()){
            data.push_front(Seq(c, n));
            break;
          }
          nit--;
          if(nit->c == c){
            nit->n += n;
            break;
          }
        }else if(p < sum+(fit->n)){
          if(fit->c == c){
            fit->n += n;
            break;
          }else{
//          cout << "kita\n";
            char nc = fit->c;
            int nn = fit->n;
//            data.erase(fit);
            fit->c = nc;
            fit->n = sum+nn - p;
            data.insert(fit, Seq(nc, p - sum));
            data.insert(fit, Seq(c, n));
//          cout << "kita\n";
            break;
          }
        }else if((++nit) == data.end()){
          if(fit->c == c){
            fit->n += n;
            break;
          }else{
            data.push_back(Seq(c, n));
            break;
          }
        }
        sum += fit->n;
      }
    }
    bool flag=true;
    if(data.size()%2 == 1){
      flag = false;
    }else{
      int count=0;
      for(fit=data.begin(),bit=--data.end();count<data.size()/2;fit++,bit--,count++){
        if(fit->c == bit->c || fit->n != bit->n){
          flag = false;
        }
      }
    }
    for(fit=data.begin(),bit=--data.end();fit!=data.end();fit++,bit--){
//      cout << fit->c << " " << fit->n << " , " << bit->c << " " << bit->n << endl;
    }
    if(flag){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
  }

  return 0;
}
