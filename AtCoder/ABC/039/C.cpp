#include <iostream>
#include <map>
using namespace std;

int main(){
    string s;
    
    map<string, string> m;

    string onkai = "WBWBWWBWBWBW";
    onkai = onkai + onkai + onkai + onkai;

    m[onkai.substr(0, 20)] = "Do";
    m[onkai.substr(2, 20)] = "Re";
    m[onkai.substr(4, 20)] = "Mi";
    m[onkai.substr(5, 20)] = "Fa";
    m[onkai.substr(7, 20)] = "So";
    m[onkai.substr(9, 20)] = "La";
    m[onkai.substr(11, 20)] = "Si";
    
    cin >> s;
    
    cout << m[s] << endl;
    return 0;
}
