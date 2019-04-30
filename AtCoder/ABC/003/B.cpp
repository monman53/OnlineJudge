#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;

    cin >> s >> t;

    bool ans = true;

    for(int i=0;i<int(s.size());i++){
        if(s[i] != '@' && t[i] != '@' && s[i] != t[i]){
            ans = false;
            break;
        }
        if(s[i] == t[i]){
            continue;
        }

        char c;

        if(s[i] == '@'){
            c = t[i];
        }else{
            c = s[i];
        }

        for(auto cc : "atcoder"){
            if(cc == c){
                ans = true;
                break;
            }
            ans = false;
        }

        if(!ans){
            break;
        }
    }

    cout << (ans ? "You can win" : "You will lose") << endl;

    return 0;
}
