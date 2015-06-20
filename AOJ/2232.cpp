#include <iostream>
using namespace std;

int h, w, n;
char data[30][30];
char map[30][30];
int di[2] = {0, 1};
int dj[2] = {1, 0};


bool remove(){
  bool rmlist[30][30];
  bool flag = false;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      rmlist[i][j] = false;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      for(int k=0;k<2;k++){
        for(int l=0;l<n;l++){
          int ni = i + di[k]*l;
          int nj = j + dj[k]*l;
          if(ni < h && nj < w){
            if(map[ni][nj] != map[i][j] || map[ni][nj] == '.'){
              break;
            }else if(l == n-1){
              for(int m=0;m<n;m++){
                rmlist[i+di[k]*m][j+dj[k]*m] = true;
              }
            }
          }else{
            break;
          }
        }
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(rmlist[i][j]){
        map[i][j] = '.';
        flag = true;
      }
    }
  }
  return flag;
}

void fall(){
  char buf[30][30];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      buf[i][j] = '.';
    }
  }
  for(int i=0;i<w;i++){
    for(int j=h-1,k=h-1;j>=0;j--){
      if(map[j][i] != '.'){
        buf[k][i] = map[j][i];
        k--;
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      map[i][j] = buf[i][j];
    }
  }
}

int main(){
  string s;
  
  cin >> h >> w >> n;

  for(int i=0;i<h;i++){
    cin >> s;
    for(int j=0;j<w;j++){
      data[i][j] = s[j];
    }
  }
  bool flag = false;
  for(int i=0;i<h;i++){
    for(int j=0;j<w-1;j++){
//      if(data[i][j] != '.' && data[i][j+1] != '.'){
      if(1){
        for(int k=0;k<h;k++){
          for(int l=0;l<w;l++){
            map[k][l] = data[k][l];
          }
        }
        map[i][j] = data[i][j+1];
        map[i][j+1] = data[i][j];
        fall();
        while(remove()){
/*          for(int g=0;g<h;g++){
            for(int f=0;f<w;f++){
              cout << map[g][f];
            }
            cout << endl;
          }
          cout << endl;*/
          fall();
        }
        int count = 0;
        for(int k=0;k<h;k++){
          for(int l=0;l<w;l++){
            if(map[k][l] == '.'){
              count++;
            }
          }
        }
        if(count == h*w){
          flag = true;
        }
      }
    }
  }
  if(flag){
    cout << "YES\n";
  }else{
    cout << "NO\n";
  }
  return 0;
}
