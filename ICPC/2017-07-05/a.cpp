#include <iostream>
#include <cstdio>
#include <map>
#include <stack>
using namespace std;

int main() {
    map<char, char> m;
    m[')'] = '(';
    m[']'] = '[';
    while(1){
        string str;
        getline(cin, str);
        // cout << str << endl;
        if(str == ".") break;
        stack<char> s;
        bool flag = false;
        for(auto c : str){
            if(c == '(' || c == '['){
                s.push(c);
            }
            if(c == ')' || c == ']'){
                if(s.size() > 0){
                    char taiou = s.top();
                    s.pop();
                    if(m[c] != taiou){
                        cout << "no" << endl;
                        flag = true;
                        break;
                    }
                }else{
                    cout << "no" << endl;
                    flag = true;
                    break;
                }
            }
        }

        if(!flag){
            if(s.size() == 0){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}
