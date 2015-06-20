#include <iostream>
#include <queue>
using namespace std;

struct queue_data{
  int i, j;
  string s;
  queue_data(int x, int y, string ss){
    i = x;
    j = y;
    s = ss;
  }
};

bool is_number(char c){
  return c >= '0' && c <= '9';
}

int comp(string s1, string s2){
  if(s1.size() == s2.size()){
    if(s1 > s2) return 1;
    if(s1 == s2) return 0;
    if(s1 < s2) return -1;
  }else if(s1.size() > s2.size()){
    return 1;
  }else{
    return -1;
  }
}

string rmzero(string s){
  string ret="";
  for(int i=0;i<s.size();i++){
    if(s[i] == '0'){
      continue;
    }else{
      for(int j=i;j<s.size();j++){
        ret = ret + s[j];
      }
      break;
    }
  }
  return ret;
}

int main(){
  int w, h;
  bool is_end[70][70];
  bool is_start[70][70];
  while(1){
    cin >> w >> h;
    if(w == 0) break;
    
    char map[70][70];
    string smax[70][70];
    string s;

    for(int i=0;i<h;i++){
      cin >> s;
      for(int j=0;j<w;j++){
        map[i][j] = s[j];
        is_end[i][j] = false;
        is_start[i][j] = false;
        smax[i][j] = "";
      }
    }

    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(is_number(map[i][j])){
          int count=0;
          if(i+1 < h){
            if(!is_number(map[i+1][j])) count++;
          }else{
            count++;
          }
          if(j+1 < w){
            if(!is_number(map[i][j+1])) count++;
          }else{
            count++;
          }
          if(count == 2){
            is_end[i][j] = true;
          }
        }
      }
    }

    for(int i=h-1;i>=0;i--){
      for(int j=w-1;j>=0;j--){
        if(is_end[i][j]){

          queue<queue_data> q;
          q.push(queue_data(i, j, ""));
          while(!q.empty()){
            int ci = q.front().i;
            int cj = q.front().j;
            string cs = q.front().s;
            q.pop();
            
            if(comp(map[ci][cj] + cs, smax[ci][cj]) > 0){
              smax[ci][cj] = map[ci][cj] + cs;
              int count=0;
              if(ci-1 >= 0){
                if(is_number(map[ci-1][cj])){
                  q.push(queue_data(ci-1, cj, map[ci][cj] + cs));
                  count++;
                }
              }
              if(cj-1 >= 0){
                if(is_number(map[ci][cj-1])){
                  q.push(queue_data(ci, cj-1, map[ci][cj] + cs));
                  count++; 
                }
              }
              if(count == 0){
                is_start[ci][cj] = true;
              }
            }
          }
        }
      }
    }
    string mmax = "";
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(is_start[i][j]){
//          cout << smax[i][j] << endl;
//          cout << rmzero(smax[i][j]) << endl;
          if(comp(rmzero(smax[i][j]), mmax) > 0)
          mmax = rmzero(smax[i][j]);
        }
      }
    }
    cout << mmax << endl;
  }
}
