#include <iostream>
#include <string>
#include <stack>
using namespace std;

string mleft, mright;
bool value[11];

string convrpn(string s){
  int lcount=0, rcount=0;
//  cout << s << "\n";
  if(s[0] == '-'){
    return convrpn(s.substr(1))+"-";
  }else if(s[0] == '('){
    for(int i=1;;i++){
      if((s[i] == '*' || s[i] == '+') && lcount == rcount){
        return convrpn(s.substr(1, i-1))+convrpn(s.substr(i+1, s.length()-i-2))+s[i];
        break;
      }else if(s[i] == '-'){
        i++;
        if(s[i] == '>' && lcount == rcount){
          return convrpn(s.substr(1, i-2))+convrpn(s.substr(i+1, s.length()-i-2))+s[i];
          break;
        }else{
          i--;
        }
      }else if(s[i] == '('){
        lcount++;
      }else if(s[i] == ')'){
        rcount++;
      }
    }
  }else{
    return s;
  }
}

bool calc(string s){
  stack<bool> st;
  bool left, right;
  for(int i=0;i<s.length();i++){
    switch(s[i]){
    case '-':
      left = st.top();
      st.pop();
      st.push(!left);
      break;
    case '+':
      right = st.top();
      st.pop();
      left = st.top();
      st.pop();
      st.push(left || right);
      break;
    case '*':
      right = st.top();
      st.pop();
      left = st.top();
      st.pop();
      st.push(left && right);
      break;
    case '>':
      right = st.top();
      st.pop();
      left = st.top();
      st.pop();
      st.push((!left) || right);
      break;
    case 'T':
      st.push(true);
      break;
    case 'F':
      st.push(false);
      break;
    default:
      st.push(value[int(s[i]-'a')]);
    }
//    cout << st.top() << " ";
  }
//  cout << "\n";
  return st.top();
}

bool ans(int n){
  bool fret, tret;
  if(n==11){
//    cout << "\n";
//    for(int i=0;i<11;i++){
//      cout << value[i] << " ";
//    }
//    cout << "\n" << mleft << " " << mright << "\n";
//    cout << ": " << mleft << " = " << calc(mleft) << " " << mright << " = " << calc(mright) << "\n";
    return (calc(mleft) == calc(mright));
  }else{
    value[n] = false;
    fret = ans(n+1);
    value[n] = true;
    tret = ans(n+1);
    return fret && tret;
  }
}

int main(){
  string s;

  while(1){
    cin >> s;
    if(s == "#") break;

    for(int i=0;i<s.length();i++){
      if(s[i] == '='){
        mleft = convrpn(s.substr(0, i));
        mright = convrpn(s.substr(i+1));
        break;
      }
    }
//    cout << mleft << " " << mright << '\n';
    if(ans(0)){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }

  return 0;
}
