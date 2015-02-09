#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int ln,rn;
    int ld[50000];
    int rd[50000];
    int sld[50000];
    int srd[50000];
    cin >> n;
    ln = n/2;
    rn = n - ln;

    for(int i=0;i<ln;i++){
        cin >> ld[i];
        sld[i] = -ld[i];
    }
    sort(sld,sld+ln);
    for(int i=0;i<rn;i++){
        cin >> rd[rn - i - 1];
        srd[rn - i - 1] = -rd[rn - i - 1];
    }
    sort(srd,srd+rn);

    for(int i=0;i<ln;i++){
        cout << sld[i] << ' ' << ld[i] << '\n';
    }
    for(int i=0;i<rn;i++){
        cout << srd[i] << ' ' << rd[i] << '\n';
    }

    for(int i=0;i<

    return 0;
}
