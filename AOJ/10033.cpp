#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    stack<char> c[101];
    int n,b,d; 
    string s;
    char buf;
    cin >> n;
    while(1){
        cin >> s;
        if(s == "push"){
            cin >> b >> buf;
            c[b].push(buf);
        }else if(s == "pop"){
            cin >> b;
            cout << c[b].top() << '\n';
            c[b].pop();
        }else if(s == "move"){
            cin >> b >>d;
            c[d].push(c[b].top());
            c[b].pop();
        }else{
            break;
        }
    }
    return 0;
}
