#include <iostream>
using namespace std;

char map[100][100];
int n;

void paint(int r, int c){
  for(int i=0;i<=c;i++){
    map[r][i] = 'o';
  }
  for(int i=c;i<n && r+1<n;i++){
    map[r+1][i] = 'o';
  }
}

int main(){
  string s;
  int count=0;

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> s;
    for(int j=0;j<s.length();j++){
      map[i][j] = s[j];
    }
  }


  for(int i=0;i<n;i++){
    for(int j=n-1;j>=0;j--){
      if(map[i][j] == '.'){
        paint(i, j);
        count++;
        break;
      }
    }
  }

  cout << count <<'\n';

  return 0;
}
