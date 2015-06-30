#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Piece{
  int w, d;
  int time;
  Piece(int x, int y, int z){
    w = x;
    d = y;
    time = z;
  }
};

bool comp(Piece p1, Piece p2){
  if(p1.time < p2.time){
    return true;
  }else if(p1.time == p2.time){
    return p1.w*p1.d < p2.w*p2.d;
  }
  return false;
}

bool last_sort(Piece p1, Piece p2){
  return p1.w*p1.d < p2.w*p2.d; 
}

int main(){
  int n, w, d;

  while(1){
    cin >> n >> w >> d;
    if(n == 0 && w == 0 && d == 0) break;

    vector<Piece> data;
    data.push_back(Piece(w, d, 0));
    vector<Piece>::iterator it;
    int p, s;

    for(int i=1;i<=n;i++){
      cin >> p >> s;
      int cw, cd;
      it = data.begin() + (p-1);
      cw = (*it).w;
      cd = (*it).d;
      data.erase(it);
      s %= (cw+cd)*2;
      if(s < cw){
        data.push_back(Piece(max(s, cw-s), cd, i));
        data.push_back(Piece(min(s, cw-s), cd, i));
      }else if(s < cw+cd){
        s -= cw;
        data.push_back(Piece(cw, max(s, cd-s), i));
        data.push_back(Piece(cw, min(s, cd-s), i));
      }else if(s < cw+cd+cw){
        s -= cw+cd;
        data.push_back(Piece(max(s, cw-s), cd, i));
        data.push_back(Piece(min(s, cw-s), cd, i));
      }else{
        s -= cw+cd+cw;
        data.push_back(Piece(cw, max(s, cd-s), i));
        data.push_back(Piece(cw, min(s, cd-s), i));
      }
      /*
      for(int j=0;j<(int)data.size();j++){
        cout << data[j].w*data[j].d << " ";
      }
      cout << endl;
      */
      sort(data.begin(), data.end(), comp);
    }

    sort(data.begin(), data.end(), last_sort);

    for(int i=0;i<(int)data.size();i++){
      cout << data[i].w*data[i].d;
      if(i != (int)data.size()-1){
        cout << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}
