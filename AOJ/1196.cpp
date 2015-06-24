#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
  vector<int> dist;
  vector<int> to;
  Node(){}
};

vector<Node> island;

int longest(int from, int to){
  int mmax = 0;
  for(int i=0;i<int(island[to].to.size());i++){
    if(island[to].to[i] != from && island[island[to].to[i]].to.size() > 1){
      mmax = max(mmax, island[to].dist[i] + longest(to, island[to].to[i]));
    }
  }
  return mmax;
}

int main(){
  int n;  
  while(1){
    cin >> n;
    if(n == 0) break;
    island.clear(); 
    vector<int> data;
    for(int i=0;i<n;i++){
      island.push_back(Node());
    }
    int sum = 0;

    for(int i=1;i<n;i++){
      int to;
      cin >> to;
      data.push_back(to-1);
      island[to-1].to.push_back(i);
      island[i].to.push_back(to-1);
    }
    for(int i=1;i<n;i++){
      int dist;
      cin >> dist;
      sum += dist;
      island[data[i-1]].dist.push_back(dist);
      island[i].dist.push_back(dist);
    }
    int mmin = sum*3;
    vector<int> maxl;
    vector<int> secl;
    int hsum=0;
    for(int i=0;i<n;i++){
      int mmax = 0;
      int msec = 0;
      if(island[i].to.size() > 1){
        for(int j=0;j<int(island[i].to.size());j++){
          if(island[island[i].to[j]].to.size() > 1){
            int dist = island[i].dist[j] + longest(i, island[i].to[j]);
            if(dist >= mmax){
              msec = mmax;
              mmax = dist;
            }else if(dist >= msec){
              msec = dist;
            }
          }
        }
      }else{
        hsum += island[i].dist[0];
      }
      maxl.push_back(mmax);
      secl.push_back(msec);
//      cout << mmax << " " << msec << '\n';
    }
    for(int i=0;i<n;i++){
      mmin = min(mmin, sum + (sum-hsum)*2 - secl[i] - maxl[i]);
    }
//    cout << sum << endl;
//    cout << hsum << endl;
    cout << mmin << endl;
//    cout << endl;
  }
  
  return 0;
}
