#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int b, p1, p2;
  int k;
  b = 0;
  for(int i=0;i<n;i++){
    b = b << 1;
    cin >> k;
    b += k;
  }
  p1 = 0;
  p2 = 0;
  for(int i=0;i<m;i++){
    cin >> k;
    for(int j=0;j<k;j++){
      p1 = (p1 << 1);
      p2 = (p2 << 1);
      p1 += i%2;
      p2 += 1-i%2;
    }
  }

  queue<int> q;
  vector<int> count(1 << 16, -1);
  q.push(b);
  count[b] = 0;

  while(!q.empty()){
    int c = q.front();
    q.pop();
    int co = count[c];
    if(c == p1 || c == p2){
      cout << co << '\n';
      break;
    }

    for(int i=0;i<n-1;i++){
      int nb;
      nb = c & ~(1 << i | 1 << (i+1));
      nb |= (c >> i)%2 << (i+1);
      nb |= (c >> (i+1))%2 << i;
      if(nb != c && count[nb] == -1){
        q.push(nb);
        count[nb] = co + 1;
      }
    }
  }

  return 0;
}
