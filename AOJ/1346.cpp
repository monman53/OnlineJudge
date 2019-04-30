#include <iostream>
#include <map>
using namespace std;
typedef long long int ll;

bool calc_mf(string s, ll n){
  ll ret = 0;
  map<int, int> data;
  for(int i=1;i<s.size();i+=2){
    if(s[i] == '*'){
      if(s[i-1] == '#'){
        data[i] = data[i-2]*(s[i+1]-'0');
        s[i-2] = '#';
      }else{
        data[i] = (s[i-1]-'0')*(s[i+1]-'0');
      }
      s[i] = '!';
      s[i-1] = '#';
      s[i+1] = '#';
    }
  }
  for(int i=0;i<s.size();i++){
    if(s[i] >= '0' && s[i] <= '9'){
      ret += int(s[i] - '0');
    }
    if(s[i] == '!'){
      ret += data[i];
    }
    if(ret > n){
      return false;
    }
  }
//  cout << ret << endl;
  return ret == n;
}

bool calc_lf(string s, ll n){
  ll ret = s[0]-'0';
  for(int i=2;i<s.size();i+=2){
    if(s[i-1] == '*'){
      ret *= s[i]-'0';
    }else{
      ret += s[i]-'0';
    }
    /*if(ret > n){
      return false;
    }*/
  }
  return ret == n;
}

int main(){
  string s;
  ll n;
  bool lf, mf;

  cin >> s;
  cin >> n;
  lf = calc_lf(s, n);
  mf = calc_mf(s, n);

  if(!lf && !mf){
    cout << "I\n";
  }else if(lf && mf){
    cout << "U\n";
  }else if(lf && !mf){
    cout << "L\n";
  }else{
    cout << "M\n";
  }
  return 0;
}
