#include <iostream>
#include <string>
#include <map>
using namespace std;

string reverse(string s){
    string ret = s;
    for(int i=0;i<s.size();i++){
        ret[i] = s[s.size()-i-1];
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        map<string, bool> train;
        string s;
        cin >> s;
        for(int i=0;i<s.size()-1;i++){
            string s1 = s.substr(0,i+1);
            string s2 = s.substr(i+1);
            string s1r = reverse(s1);
            string s2r = reverse(s2);

            train[s1  +  s2] = true;
            train[s2  +  s1] = true;
            
            train[s1r +  s2] = true;
            train[s2  + s1r] = true;
            
            train[s1  + s2r] = true;
            train[s2r +  s1] = true;
            
            train[s1r + s2r] = true;
            train[s2r + s1r] = true;
        }
        cout << train.size() << '\n';
    }
    return 0;
}
