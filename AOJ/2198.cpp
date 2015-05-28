#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){ 
  string l;
  int n, p, a, b, c, d, e, f, s, m;
  while(1){
    set<pair<double, string> > ans;
    cin >> n;
    if(n==0) break;
    for(int i=0;i<n;i++){
      cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
      ans.insert(pair<double, string>(-(m*f*s - p)/double(a+b+c+(d+e)*m), l));
    }
    set<pair<double, string> >::iterator it;
    for(it=ans.begin();it!=ans.end();it++){
      cout << (*it).second /*<< '\t' << (*it).first*/ << '\n';
    }
    cout << "#\n";
  }

  return 0;
}
