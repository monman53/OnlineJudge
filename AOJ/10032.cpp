#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s;
    char buf;
    stack<char> c;
    while(1){
        cin >> s;
        if(s == "push"){
            cin >> buf;
            c.push(buf);
        }else if(s == "pop"){
            cout << c.top() << '\n';
            c.pop();
        }else if(s == "quit"){
            break;
        }
    }
    return 0;
}
