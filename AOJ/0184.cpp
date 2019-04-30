#include <iostream>
#include <map>
using namespace std;

int main(){
    while(1){
        map<int, int> data;
        int n;
        cin >> n;
        if(n == 0) break;
        for(int i=0;i<7;i++) data[i] = 0;

        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            if(a >= 70) a = 60;
            data[a/10] += 1;
        }

        for(int i=0;i<7;i++) cout << data[i] << '\n';
    }

    return 0;
}
