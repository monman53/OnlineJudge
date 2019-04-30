#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Gap{
  int id;
  int r,R;
  int bridge;
  Gap(int x, int y, int z){
    id = x;
    r = y;
    R = z;
  }
};

struct Bridge{
  int id;
  bool used;
  int length;
  Bridge(int x, int y, bool z){
    id = x;
    length = y;
    used = z;
  }
};

bool sort_gap(Gap g1, Gap g2){
  if(g1.r < g2.r){
    return true;
  }else if(g1.r == g2.r && g1.R < g2.R){
    return true;
  }else{
    return false;
  }
}

bool sort_ans(Gap g1, Gap g2) {
  return g1.id < g2.id;
}

bool sort_bridge(Bridge b1, Bridge b2){
  return b1.length < b2.length;
}

int main(){
  int n, m;
  int l, r, bl, br;
  cin >> n >> m;

  vector<Gap> gap;
  vector<Bridge> bridge;

  for(int i=0;i<n;i++){
    cin >> l >> r;
    if(i!=0){
      gap.push_back(Gap(i, l-br, r-bl));     
    }
    bl = l;
    br = r;
  }
  sort(gap.begin(), gap.end(), sort_gap);
  int a;
  for(int i=0;i<m;i++){
    cin >> a;
    bridge.push_back(Bridge(i+1, a, false));
  }
  sort(bridge.begin(), bridge.end(), sort_bridge);

  for(int i=0;i<(int)gap.size();i++){
    for(int j=0;j<(int)bridge.size();j++){
      if(gap[i].r <= bridge[j].length && gap[i].R >= bridge[j].length && !bridge[j].used){
        gap[i].bridge = bridge[j].id;
        bridge[j].used = true;
        break;
      }else if(j==(int)bridge.size()-1){
        cout << "No\n";
        return 0;
      }
    }
  }

  sort(gap.begin(), gap.end(), sort_ans);
  cout << "Yes\n";
  for(int i=0;i<(int)gap.size();i++){
    cout << gap[i].bridge << " ";
  }
  cout << endl;
  return 0;
}
