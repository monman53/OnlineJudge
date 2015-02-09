#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        int n;
        int ba;
        int data[10];
        string s;
        cin >> n;
        for(int i=0;i<n;i++) data[i] = 0;
        ba = 0;
        if(n == 0) break;
        cin >> s;
        for(int i=0;i<s.size();i++){
            switch(s[i]){
            case 'M':
                data[i%n]++;
                break;
            case 'S':
                ba += data[i%n] + 1;
                data[i%n] = 0;
                break;
            case 'L':
                data[i%n] += ba + 1;
                ba = 0;
                break;
            }
        }
        sort(data,data+n);
        for(int i=0;i<n;i++){
            cout << data[i] << ' ';
        }
        cout << ba << '\n';
    }
    return 0;
}
