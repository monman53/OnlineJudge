#include <iostream>
#include <algorithm>
using namespace std;



int main(){
  int b[2][3];
  int c[3][2];

  char map[10] = "oooooxxxx";

  int ans_chokudai = 0;
  int ans_chokuko = 0;
  int sum_max=0;
  
  for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
      cin >> b[i][j];
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
      cin >> c[i][j];
    }
  }

  int count=0;
  do{
    int chokudai = 0;
    int chokuko = 0;
    for(int i=0;i<2;i++){
      for(int j=0;j<3;j++){
        if(map[i*3+j] == map[(i+1)*3+j]){
          chokudai += b[i][j];
        }else{
          chokuko += b[i][j];
        }
      }
    }
    for(int i=0;i<3;i++){
      for(int j=0;j<2;j++){
        if(map[i*3+j] == map[i*3+j+1]){
          chokudai += c[i][j];
        }else{
          chokuko += c[i][j];
        }
      }
    }
    
    /*if(chokudai+chokuko >= sum_max){
      sum_max = chokudai + chokuko;
      ans_chokudai = chokudai;
      ans_chokuko = chokuko;
    }*/
    if(sum_max <= chokudai+chokuko && chokudai >= ans_chokudai){
      ans_chokudai = chokudai;
      ans_chokuko = chokuko;
      sum_max = chokudai + chokuko;
    }
  }while(next_permutation(map, map+9));
  cout << ans_chokudai << '\n' << ans_chokuko << '\n';

  return 0;
}
