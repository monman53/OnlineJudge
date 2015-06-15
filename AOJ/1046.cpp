#include <iostream>
using namespace std;

int h, w;
int girlmin[20][20];
int map[20][20];
int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};
bool log[20][20][10];

void calcmin(int ci, int cj, int n){
  int ni, nj;
  girlmin[ci][cj] = n;
  for(int i=0;i<4;i++){
    ni = ci + di[i];
    nj = cj + dj[i];
    if(ni >= 0 && ni < h && nj >= 0 && nj < w){
      if(map[ni][nj] == '.' && girlmin[ni][nj] == -1){
        calcmin(ni, nj, n+1);
      }
    }
  }
}

int main(){
  string s;
  int girli, girlj, ghosti, ghostj;
  while(1){
    cin >> h >> w;
    if(h==0 && w==0) break;

    for(int i=0;i<h;i++){
      cin >> s;
      for(int j=0;j<w;j++){
        switch(s[j]){
        case 'A':
          girli = i;
          girlj = j;
          map[i][j] = '.';
          break;
        case 'B':
          ghosti = i;
          ghostj = j;
          map[i][j] = '.';
          break;
        default:
          map[i][j] = s[j];
          break;
        }
        girlmin[i][j] = -1;
        for(int k=0;k<10;k++){
          log[i][j][k] = false;
        }
      }
    }
    cin >> s;

    calcmin(girli, girlj, 0);

    int time=0;
    int ni, nj;
    for(int i=0;;i++,time++){
      i=i%s.length();
      switch(s[i]){
      case '5':
        ni = ghosti;
        nj = ghostj;
        break;
      case '8':
        ni = ghosti-1;
        nj = ghostj;
        break;
      case '6':
        ni = ghosti;
        nj = ghostj+1;
        break;
      case '4':
        ni = ghosti;
        nj = ghostj-1;
        break;
      case '2':
        ni = ghosti+1;
        nj = ghostj;
        break;
      }
      if(!(ni >= 0 && ni < h && nj >= 0 && nj < w)){
        ni = ghosti;
        nj = ghostj;
      }

//      cout << "kita" << s[i];
      if(log[ghosti][ghostj][i] && time > h*w){
        cout << "impossible\n";
        break;
      }
      log[ghosti][ghostj][i] = true;
      if(girlmin[ghosti][ghostj] != -1 && girlmin[ghosti][ghostj] <= time){
        cout << time << " " << ghosti << " " << ghostj << '\n';
        break;
      }

      ghosti = ni;
      ghostj = nj;
    }


    /*for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        cout << girlmin[i][j] << " ";
      }
      cout << '\n';
    }*/

  }
  return 0;
}
