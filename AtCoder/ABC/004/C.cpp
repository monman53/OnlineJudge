#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s = "123456";
    vector<string> vec;

    for(int i=0;;i++){
        // swap
        char tmp = s[i%5];
        s[i%5] = s[i%5+1];
        s[i%5+1] = tmp;

        if(find(vec.begin(), vec.end(), s) != vec.end()){
            break;
        }

        vec.push_back(s);
    }

    long int n;
    cin >> n;

    cout << vec[(n-1)%vec.size()] << endl;

    return 0;
}
