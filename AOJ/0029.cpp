#include <iostream>
#include <map>
using namespace std;
 
int main(){
    string s,maxfs,maxss;
    int maxf=0,maxs=0;
    map<string, int> count;
     
    while(cin >> s){
        if(count.find(s) == count.end()){
            count[s] = 1;
        }else{
            count[s] += 1;
        }
        if(count[s] > maxf){
            maxf = count[s];
            maxfs = s;
        }
        if(s.size() > maxs){
            maxs = s.size();
            maxss = s;
        }
    }
    cout << maxfs << ' ' << maxss << '\n';
    return 0;
}
