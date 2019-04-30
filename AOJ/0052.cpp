#include <iostream>
using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        int sum=0;
        for(int i=5;i<=n;i+=5){
            int j,count;
            for(j=i,count=0;j%5 == 0;j /= 5,count++){};
            sum += count;
        }
        cout << sum << '\n';
    }
    return 0;
}
