#include <iostream>
#include <string>
#include <map>
using namespace std;
 
int main() {
    map<string, bool> usr;
    int n,m;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        usr[s] = true;
    }
    cin >> m;
    bool opend = false;
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        if(usr.find(s) == usr.end()){
            cout << "Unknown "+s+'\n';
        }else{
            if(opend){
                cout << "Closed by ";
            }else{
                cout << "Opened by ";
            }
            cout << s+'\n';
            opend = !opend;
        }
    }
    return 0;
}
