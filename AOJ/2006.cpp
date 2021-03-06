#include <iostream>
#include <string>
using namespace std;

int main(){
    char data[10][6] = {{0,   0,   0,   0,   0,   0},
                        {5, '.', ',', '!', '?', ' '},
                        {3, 'a', 'b', 'c',   0,   0},
                        {3, 'd', 'e', 'f',   0,   0},
                        {3, 'g', 'h', 'i',   0,   0},
                        {3, 'j', 'k', 'l',   0,   0},
                        {3, 'm', 'n', 'o',   0,   0},
                        {4, 'p', 'q', 'r', 's',   0},
                        {3, 't', 'u', 'v',   0,   0},
                        {4, 'w', 'x', 'y', 'z',   0}};

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int count=0;
        int last=0;
        for(int j=0;j<s.size();j++){
            int now = s[j] - '0';
            if(last > 0 && now == 0){
                cout << data[last][(count-1)%int(data[last][0])+1];
                count = 0;
            }
            if(now > 0){
                count++;
            }
            last = now;
        }
        cout << '\n';
    }
    return 0;
}
