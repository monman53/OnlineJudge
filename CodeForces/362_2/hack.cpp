#include <string>
#include <vector>
using namespace std;

int main(){
    long long b, eIndex;
    string s, res="";
    cin >> s;
    res += s.substr(0, 1);
    for(eIndex = s.size()-1;s[eIndex]!='e';--eIndex){
    }
    res+=s.substr(2, eIndex-2);
    if(res.size()==2&&stoll
}
