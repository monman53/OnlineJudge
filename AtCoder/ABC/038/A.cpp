#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    cout << (s[s.length()-1] == 'T' ? "YES" : "NO") << endl;
    return 0;
}
