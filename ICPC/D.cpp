#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int SZ = 510; 
bool visit[2][SZ][SZ];
int vwal[SZ][SZ];
int hwal[SZ][SZ];


bool dfs(int h,int w,int r,int c,int rev){
  visit[rev][r][c] = true;
  if(!(rev ^ hwal[r][c])){
    if(r-1 < 0)return true;
    else if(!visit[0][r-1][c] && !visit[1][r-1][c] 
	    && dfs(h,w,r-1,c,0) && dfs(h,w,r-1,c,1))return true;
  }
  if(!(rev ^ hwal[r+1][c])){
    if(r+1 >= h)return true;
    else if(!visit[0][r+1][c] && !visit[1][r+1][c] 
	    && dfs(h,w,r+1,c,0) && dfs(h,w,r+1,c,1))return true;
  }
  if(!(rev ^ vwal[r+1][c])){
    if(c-1 < 0)return true;
    else if(!visit[0][r][c-1] && !visit[1][r][c-1] 
	    && dfs(h,w,r,c-1,0) && dfs(h,w,r,c-1,1))return true;
  }
  if(!(rev ^ vwal[r+1][c+1])){
    if(c+1 >= w)return true;
    else if(!visit[0][r][c+1] && !visit[1][r][c+1] 
	    && dfs(h,w,r,c+1,0) && dfs(h,w,r,c+1,1))return true;
  }
  return false;
}


void solve(int h,int w,int r,int c){
  --r;--c;
  for(int i = 0;i < h;++i){
    for(int j = 0;j < w;++j){
      visit[0][i][j] = false;
      visit[1][i][j] = false;
    }
  }
  for(int i = 0;i < w;++i){
    cin >> hwal[0][i];
  }
  for(int i = 1;i <= h;++i){
    for(int j = 0;j <= w;++j){
      cin >> vwal[i][j];
    }
    for(int j = 0;j < w;++j){
      cin >> hwal[i][j];
    }
  }
  if(dfs(h,w,r,c,0))cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main(void){
  int h,w,r,c;
  while(cin >> h >> w >> r >> c,h+w+r+c)solve(h,w,r,c);
  return 0;
}
