#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

class Era{
  public:
  string name;
  ll begin, end;
  Era(){}
  Era(string s, int i, int j){
    begin = j-i+1;
    end = j;
    name = s;
  }
};

int main(){
  int n, q, b, w;
  string s;
  while(1){
    cin >> n >> q;
    if(n == 0 && q == 0) break;
    
    vector<Era> data;

    for(int i=0;i<n;i++){
      cin >> s >> b >> w;
      data.push_back(Era(s, b, w));
    }
    for(int i=0;i<q;i++){
      cin >> w;
      for(int i=0;i<n;i++){
        if(data[i].begin <= w && w <= data[i].end){
          cout << data[i].name << " " << (w - data[i].begin + 1) << '\n';
          break;
        }
        if(i == n-1){
          cout << "Unknown\n";
        }
      }
    }
  }
  return 0;
}
