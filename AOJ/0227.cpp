#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        int n,m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        int count=0;
        int data[1000];
        for(int i=0;i<n;i++){
            int p;
            cin >> p;
            count += p;
            data[i] = -p;
        }
        sort(data,data+n);
        for(int i=m-1;i<n;i+=m){
            count += data[i];
        }
        cout << count << '\n';
    }
    return 0;
}
