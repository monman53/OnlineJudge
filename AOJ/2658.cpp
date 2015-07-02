#include <iostream>
#include <vector>
using namespace std;

int n;
struct Node{
  int c;
  vector<int> to;
  Node(int x){c = x;}
};
vector<Node> node;
int cost[1000][1000];

int ans(int from, int to){
  int res = 0;
  for(int i=0;i<(int)node[to].to.size();i++){
    if(node[to].to[i] != from){
      if(node[node[to].to[i]].c > 0){
        res += cost[to][node[to].to[i]];
      }else{
        res += min(cost[to][node[to].to[i]], ans(to, node[to].to[i]));
      }
    }
  }
  return res;
}

int main(){
  cin >> n;
  // init
  for(int i=0;i<n;i++){
    node.push_back(Node(0));
    for(int j=0;j<n;j++){
      cost[i][j] = 0;
    }
  }

  // input
  for(int i=1;i<n;i++){
    cin >> node[i].c;
  }
  for(int i=0;i<n-1;i++){
    int u, v, p;
    cin >> u >> v >> p;
    node[u].to.push_back(v);
    node[v].to.push_back(u);
    cost[u][v] = cost[v][u] = p;
  }
  
  // output
  cout << ans(0, 0) << '\n';
}
