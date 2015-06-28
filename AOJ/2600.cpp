#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

struct Range{
  ll l, r;
  Range(ll x, ll y){
    l = x;
    r = y;
  }
};

struct Data{
  int x, y, w;
  Data(ll i, ll j, ll k){
    x = i;
    y = j;
    w = k;
  }
};

bool comp(Data d1, Data d2){
  if(d1.w > d2.w){
    return true;
  }else if(d1.w == d2.w){
    return d1.x+d1.y < d2.x+d2.y;
  }
  return false;
}

int main(){
  ll N, W, H;
  cin >> N >> W >> H;

  vector<Range> tate, yoko;
  ll x, y, w;
  ll l, r;

  vector<Data> data;
  for(ll i=0;i<N;i++){
    cin >> x >> y >> w;
    data.push_back(Data(x, y, w));
  }
  sort(data.begin(), data.end(), comp);

  for(ll i=0;i<N;i++){
    x = data[i].x;
    y = data[i].y;
    w = data[i].w;
    // tate
    vector<Range> new_tate;
    l = max(0LL, y-w);
    r = min(H, y+w);
    for(int j=0;j<(int)tate.size();j++){
      if((l - tate[j].r)*(r - tate[j].l) <= 0){
        r = max(tate[j].r, r);
        l = min(tate[j].l, l);
      }else{
        new_tate.push_back(tate[j]);
      }
    }
    new_tate.push_back(Range(l, r));
    tate = new_tate;

    // yoko
    vector<Range> new_yoko;
    l = max(0LL, x-w);
    r = min(W, x+w);
    for(int j=0;j<(int)yoko.size();j++){
      if((l - yoko[j].r)*(r - yoko[j].l) <= 0){
        r = max(yoko[j].r, r);
        l = min(yoko[j].l, l);
      }else{
        new_yoko.push_back(yoko[j]);
      }
    }
    new_yoko.push_back(Range(l, r));
    yoko = new_yoko;

    if(yoko[0].l == 0 && yoko[0].r == W || tate[0].l == 0 && tate[0].r == H){
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
}
