#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, m, q;

int main(){
  while(1){
    cin >> n >> m >> q;
    if(n == 0 && m == 0 && q == 0) break;
    
    string s1, s2;
    vector<string> switches;
    vector<bool> sw;
    vector<string> results;
    map<string, int> data;
 
    for(int i=0;i<n;i++){
      switches.push_back("");
      sw.push_back(false);
    }
    for(int i=0;i<m;i++){
      results.push_back("");
    }

    for(int i=0;i<q;i++){
      cin >> s1 >> s2;
      for(int j=0;j<n;j++){
        if(s1[j] == '1' && !sw[j]){
          switches[j] += '1';
          sw[j] = true;
          continue;
        }
        if(s1[j] == '1' && sw[j]){
          switches[j] += '0';
          sw[j] = false;;
          continue;
        }
        if(s1[j] == '0' && !sw[j]){
          switches[j] += '0';
          continue;
        }
        if(s1[j] == '0' && sw[j]){
          switches[j] += '1';
          continue;
        }
      }
      for(int j=0;j<m;j++){
        results[j] += s2[j];
      }
    }

    for(int i=0;i<n;i++){
//      cout << switches[i] << endl;
      if(data.find(switches[i]) != data.end()){
        data[switches[i]] = -1;
      }else{
        data[switches[i]] = i;
      }
    }
    string ret="";
    for(int i=0;i<m;i++){
      if(data.find(results[i]) == data.end()){
        ret += '?';
      }else if(data[results[i]] == -1){
        ret += '?';
      }else{
        if(data[results[i]] >= 10){
          ret += char('A' + data[results[i]] - 10);
        }else{
          ret += char('0' + data[results[i]]); 
        }
      }
    }
    cout << ret << '\n';
  }
  return 0;
}
