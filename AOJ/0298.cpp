#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main(){
  set<pair<int, int> > ans;
  set<pair<int, int> >::iterator it;

  int n, h, m;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> h >> m;
    ans.insert(pair<int, int>(h, m));
  }
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> h >> m;
    ans.insert(pair<int, int>(h, m));
  }

  for(it=ans.begin();it!=ans.end();){
    h = (*it).first;
    m = (*it).second;
    printf("%d:%02d", h, m);
    if(++it != ans.end()){
      printf(" ");
    }else{
      break;
    }
  }
  printf("\n");
}
