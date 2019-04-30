#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int> > tree;
vector<string> data;

void print(int m, int n){
  for(int i=0;i<n;i++){
    cout << '.';
  }
  cout << data[m]  << '\n';
  for(int i=0;i<int(tree[m].size());i++){
    print(tree[m][i], n+1);
  }
}

int main(){
  int n;
  int to;
  string s;

  cin >> n;
  
  for(int i=0;i<n;i++){
    cin >> to;
    cin >> s;
    data.push_back(s);
    tree[to-1].push_back(i);
  }

  print(0, 0);

  return 0;
}
