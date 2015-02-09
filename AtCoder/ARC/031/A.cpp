#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool kaibun=true;
    for(int i=0;i<s.size()/2;i++){
        if(s[i] != s[s.size() - i - 1]){
            kaibun = false;
        }
    }
    cout << ((kaibun) ? "YES" : "NO") << '\n';
    return 0;
}
