#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct d{
  int m;
  vector<struct d> b;
}D;

int sn(string s){
  int v = s.size();
  return (v ? s[v-1]-'0'+10*sn(s.substr(0,v-1)) : 0 );
}

bool comp(D d1, D d2){
  return d1.m < d2.m;
}

D ans(string s){
  D ku;
  ku.m=0;
  if(s[1] == '['){
    for(int i=1,ib=1,lc=0,rc=0;i<s.size();i++){
      if(s[i]=='[') lc++;
      if(s[i]==']') rc++;
      if(lc==rc){
        ku.b.push_back(ans(s.substr(ib, i-ib+1)));
        ib=i+1;
      }
    }
    sort(ku.b.begin(), ku.b.end(), comp);
    for(int i=0;i<ku.b.size()/2+1;i++){
      ku.m += ku.b[i].m;
    }
  }else{
    ku.m = sn(s.substr(1, s.size()-2))/2+1;
  }
  return ku;
}

int main(){
  int n;
  string s;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> s;
    cout << ans(s).m << endl;
  }
  return 0;
}
