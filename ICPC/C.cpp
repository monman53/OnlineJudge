#include <iostream>
#include <vector>
using namespace std;

int mmax;
int h, w;
char map[16][2][2];
char drop_block[3][2][2][2];
int pat[8][2][2] = {{{0,1},{0,1}},
                    {{1,1},{0,0}},
                    {{1,0},{1,0}},
                    {{0,0},{1,1}},
                    {{0,1},{0,0}},
                    {{1,0},{0,0}},
                    {{0,0},{1,0}},
                    {{0,0},{0,1}}};
int now_block[2][2][2];
int buf_block[2][2][2];

int pattern();
void move(int n);

int remove(){
  int rmcount=0;
  for(int i=0;i<10+2+2+2;i++){
    int count=0;
    for(int j=0;j<2;j++){
      for(int k=0;k<2;k++){
        if(map[i][j][k] == '#'){
          count++;
        }
      }
    }
    if(count == 4){
      for(int j=i;j<10+2+2+1;j++){
        for(int k=0;k<2;k++){
          for(int l=0;l<2;l++){
            map[i][k][l] = map[i+1][k][l];
          }
        }
      }
      rmcount++;
    }
  }
  return rmcount;
}

void dfs(int n, int count){
  int z;
  int p;
  int i;
  char buf_map[16][2][2];
  p = pattern();
  if(p >= 4){
    i = 4;
  }else if(p >= 0){
    i = 2;
  }else{
    i = 1;
  }

  for(int j=0;j<i;j++){
    for(int k=0;k<16;k++){
      for(int l=0;k<2;k++){
        for(int m=0;m<2;m++){
          buf_block[k][l][m] = map[k][l][m];
        }
      }
    }
    move(pattern());
    for(z=h+2*n;;z--){
      bool flag=false;
      for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
          for(int l=0;l<2;l++){
            if(now_block[j][k][l] == '*' && map[z+j][k][l] == '#'){
              flag=true;
              z++;
            }
          }
        }
      }
      if(flag || z == 0){
        for(int j=0;j<2;j++){
          for(int k=0;k<2;k++){
            for(int l=0;l<2;l++){
              if(now_block[j][k][l] == '#'){
                map[z+j][k][l] = now_block[j][k][l];
              }
            }
          }
        }
        break;
      }
    }

    if(n != 2){
      dfs(n+1, count + remove());
    }else{
      mmax = max(mmax, count);
    }
  

    for(int k=0;k<16;k++){
      for(int l=0;k<2;k++){
        for(int m=0;m<2;m++){
          buf_block[k][l][m] = map[k][l][m];
        }
      }
    }
  }
}

int main(){
  string s;

  while(1){
    cin >> h >> w;
    if(h == 0 && w == 0) break;

    for(int i=0;i<h;i++){
      for(int j=0;j<2;j++){
        cin >> s;
        for(int k=0;k<2;k++){
          map[i][j][k] = s[k];
        }
      }
    }
    
    for(int i=0;i<w;i++){
      for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
          cin >> s;
          for(int l=0;l<2;l++){
            drop_block[i][j][k][l] = s[l];
            now_block[j][k][l] = s[l];
          }
        }
      }
      //cout << pattern();
      //move(pattern());

    }
    mmax = 0;
      dfs(0, 0);
      cout << mmax << '\n';
    //cout << '\n';
  }
  return 0;
}

int pattern(){
  int count[2][2];
  int sum=0;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      count[i][j] = 0;
      for(int k=0;k<2;k++){
        if(now_block[k][i][j] == '#'){
          count[i][j]++;
          sum++;
        }
      }
    }
  }
  int countdata[8];
  for(int i=0;i<8;i++){
    countdata[i] = 0;
    for(int j=0;j<2;j++){
      for(int k=0;k<2;k++){
        countdata[i] += count[j][k] * pat[i][j][k];
      }
    }
  }
  if(countdata[4] == sum) return 4;
  if(countdata[5] == sum) return 5;
  if(countdata[6] == sum) return 6;
  if(countdata[7] == sum) return 7;
  if(countdata[2] == 0) return 0;
  if(countdata[3] == 0) return 1;
  if(countdata[0] == 0) return 2;
  if(countdata[1] == 0) return 3;

  return -1;
}

void move(int n){
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<2;k++){
        buf_block[i][j][k] = '.';
      }
    }
  }
  
  switch(n){
  case 0:
  case 2:
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
          buf_block[i][j][k] = now_block[i][j][1-(k%2)];
        }
      }
    }
    break;
  case 1:
  case 3:
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
          buf_block[i][k][j] = now_block[i][1-(k%2)][j];
        }
      }
    }
    break;
  case 4:
    for(int i=0;i<2;i++){
      buf_block[i][0][0] = now_block[i][0][1];
    }
    break;
  case 5:
    for(int i=0;i<2;i++){
      buf_block[i][1][0] = now_block[i][0][0];
    }
    break;
  case 6:
    for(int i=0;i<2;i++){
      buf_block[i][1][1] = now_block[i][1][0];
    }
    break;
  case 7:
    for(int i=0;i<2;i++){
      buf_block[i][0][1] = now_block[i][1][1];
    }
    break;
  default:
    return;
  }


  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<2;k++){
        now_block[i][j][k] = buf_block[i][j][k];
      }
    }
  }
}
