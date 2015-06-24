#include <iostream>
using namespace std;

int t, n;
string num;
bool cut[7];
int mmax;
int count;
string anss;

int ston(string s){
  int ret=0;
  for(int i=s.size()-1,j=1;i>=0;i--,j*=10){
    ret += (s[i]-'0')*j;
  }
  return ret;
}

void ans(int ci){
  if(ci == n){
    int sum = 0;
    string s = "";
    for(int i=1,start=0;i<=n;i++){
      if(cut[i]){
        sum += ston(num.substr(start, i-start));
        s += num.substr(start, i-start) + " ";
        start = i;
      }
    }
    if(sum <= t){
      if(sum > mmax){
        mmax = sum;
        anss = s.substr(0, s.size()-1);
        count = 0;
      }else if(sum == mmax){
        count++;
      }
      //cout << mmax << " " << count << " " << s << endl;
    }
    return;
  }
  cut[ci] = false;
  ans(ci + 1);
  cut[ci] = true;
  ans(ci + 1);
}

int main(){

  while(1){
    cin >> t >> num;
    if(t == 0 && num == "0") break;
    
    n = num.size();
    cut[0] = true;
    cut[n] = true;
    mmax = 0;
    count = 0;

    if(t == ston(num)){
      cout << t << " " << num << '\n';
      continue;
    }

    int sum = 0;
    for(int i=0;i<num.size();i++){
      sum += num[i]-'0';
    }
    if(sum > t){
      cout << "error\n";
      continue;
    }

    ans(1);

    if(count != 0){
      cout << "rejected\n";
    }else{
      cout << mmax << " " << anss << '\n';
    }
  }

  return 0;
}
