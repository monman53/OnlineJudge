#include <iostream>
#include <algorithm>
using namespace std;

typedef struct data{
  int solved;
  int time;
  int p[10];
  int id;
}DATA;

bool comp(DATA data1, DATA data2){
  if(data1.solved > data2.solved) return true;
  if(data1.solved < data2.solved) return false;
  if(data1.time < data2.time) return true;
  if(data1.time > data2.time) return false;
  return data1.id > data2.id;
}

bool draw(DATA data1, DATA data2){
  return data1.solved == data2.solved && data1.time == data2.time;
}

int main(){
  int M, T, P, R;
  int m, t, p, j;

  while(1){
    cin >> M >> T >> P >> R;
    if(M == 0) break;

    DATA team[T];

    // init
    for(int i=0;i<T;i++){
      team[i].id = i+1;
      team[i].time = 0;
      team[i].solved = 0;
      for(int j=0;j<P;j++){
        team[i].p[j] = 0;
      }
    }

    for(int i=0;i<R;i++){
      cin >> m >> t >> p >> j;
      if(j==0){
        team[t-1].time += team[t-1].p[p-1] + m;
        team[t-1].solved++;
      }else{
        team[t-1].p[p-1] += 20;
      }
    }

    sort(team, team+T, comp);

    for(int i=0;i<T;i++){
      if(i==T-1){
        cout << team[i].id << '\n';
      }else{
        if(draw(team[i], team[i+1])){
          cout << team[i].id << "=";
        }else{
          cout << team[i].id << ",";
        }
      }
    }
  }
  

  return 0;
}
