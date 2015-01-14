#include <iostream>
#include <vector>
using namespace std;

int main(){
    int d[20];
    int x[101];
    int l;
    while(1){
        int n,l;
        cin >> n >> l;
        if(n == 0) break;

        for(int i=1;i<=l;i++){
            x[i] = -1;
        }

        for(int i=0;i<n;i++){
            char c;
            int p;
            cin >> c >> p;
            d[i] = (c == 'R' ? 1 : -1);
            x[p] = i;
        }

        vector<set<int, int> > log;
        int time=0;
        while(vector.size() != n){
            for(int i=1;i<=l;i++){
                if(x[i] >= 0){
                    for(int j=1;j<=2;j++){
                        if(i + d[x[i]]*j == 0){
                        }
                    }
                }
            }
        }
    }
    return 0;
}
