#include <iostream>
#include <map>
using namespace std;

typedef struct tudent{
  bool login[720];
  map<int, int> pc;
}STUDENT;

int main(){
  int N, M, r, t, n, m, s, q, ts, te;
  while(1){
    cin >> N >> M;
    if(N == 0) break;

    STUDENT st[M+1];
    for(int i=0;i<M+1;i++){
      for(int j=0;j<720;j++){
        st[i].login[j] = false;
      }
    }
    cin >> r;
    for(int i=0;i<r;i++){
      cin >> t >> n >> m >> s;
      if(s == 1){
        st[m].pc[n] = t;
      }else{
        for(int j=st[m].pc[n]-540;j<t-540;j++){
          st[m].login[j] = true;
        }
        st[m].pc.erase(n);
      }
    }
    cin >> q;
    for(int i=0;i<q;i++){
      int count=0;
      cin >> ts >> te >> m;
      for(int j=ts-540;j<te-540;j++){
        if(st[m].login[j]){
          count++;
        }
      }
      cout << count << '\n';;
    }
  }
  return 0;
}
