#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

class Train{
  public:
  int hatsu, chaku;
  Train(){}
  Train(int i, int j){hatsu=i;chaku=j;}
  bool operator()(Train t1, Train t2){
    return t1.chaku > t2.chaku;
  }
};

bool sort_comp(Train t1, Train t2){
  return t1.hatsu <= t2.hatsu;
}

int main(){
  int n, h, m, s;
  while(1){
    scanf("%d", &n);
    if(n == 0) break;
    
    priority_queue<Train, vector<Train>, Train> train;
    vector<Train> data;
    int count=0;

    for(int i=0;i<n;i++){
      scanf("%d:%d:%d", &h, &m, &s);
      int hatsu = 60*60*h + 60*m + s;
      scanf("%d:%d:%d", &h, &m, &s);
      int chaku = 60*60*h + 60*m + s;
      data.push_back(Train(hatsu, chaku));
    }
    sort(data.begin(), data.end(), sort_comp);
    for(int i=0;i<n;i++){
      if(train.empty() || data[i].hatsu < train.top().chaku){
        train.push(data[i]);
        count++;
      }else{
        train.pop();
        train.push(data[i]);
      }
    }

    cout << count << endl;
  }
}
