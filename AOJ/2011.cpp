#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
  while(1){
    int n;
    cin >> n;
    if(n == 0) break;
    vector<set<int>> data(30);

    for(int i=0;i<n;i++){
      int f;
      cin >> f;
      for(int j=0;j<f;j++){
        int m;
        cin >> m;
        data[m-1].insert(i);
      }
    }

//    cout << "debug\n";

    vector<set<int>> ans(n);
    for(int i=0;i<30;i++){
//      cout << i << endl;
      if(!data[i].empty()){
        for(set<int>::iterator it1=data[i].begin();it1!=data[i].end();it1++){
          for(set<int>::iterator it2=data[i].begin();it2!=data[i].end();it2++){
//            cout << *it2 << ":";
            for(set<int>::iterator it3=ans[*it2].begin();it3!=ans[*it2].end();it3++){
//              cout << *it3 << " ";
              ans[*it1].insert(*it3);
            }
//            cout << endl;
          }
        }
        for(set<int>::iterator it1=data[i].begin();it1!=data[i].end();it1++){
          for(set<int>::iterator it2=data[i].begin();it2!=data[i].end();it2++){
            ans[*it1].insert(*it2);
          }
        }
      }
      bool end=false;
      for(int j=0;j<n;j++){
        if(ans[j].size() == n){
          cout << i+1 << '\n';
          end=true;
          break;
        }
      }
      if(end) break;
      if(i == 29){
        cout << -1 << '\n';
      }
    }
  }
  return 0;
}
