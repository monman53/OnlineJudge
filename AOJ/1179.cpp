#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int y,m,d;
        int past = 0;
        cin >> y >> m >> d;
        past = (y-1)*(20*5+19*5) + ((y-1)/3)*(1*5) + (m-1)*20 + ((y%3 == 0)? 0:-1*((m-1)/2)) + (d-1);
        cout << (196470 - past) << '\n';
    }
    return 0;
}
