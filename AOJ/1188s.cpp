#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;typedef struct d{int m;vector<struct d>b;}D;int c(string s){int v=s.size();return (v?s[v-1]-'0'+10*c(s.substr(0,v-1)):0);}bool r(D d1,D d2){return d1.m<d2.m;}D a(string s){D k;k.m=0;if(s[1]=='['){for(int i=1,ib=1,lc=0,rc=0;i<s.size();i++){if(s[i]=='[')lc++;if(s[i]==']')rc++;if(lc==rc){k.b.push_back(a(s.substr(ib,i-ib+1)));ib=i+1;}}sort(k.b.begin(),k.b.end(),r);for(int i=0;i<k.b.size()/2+1;i++){k.m+=k.b[i].m;}}else{k.m=c(s.substr(1,s.size()-2))/2+1;}return k;}int main(){int n;string s; cin>>n;for(int i=0;i<n;i++){cin>>s;cout<<a(s).m<<'\n';}return 0;}
