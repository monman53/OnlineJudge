#include <iostream>
#define INF 999999999
using namespace std;

int main(){
    while(1){
        int n;
        int ld[10][10];
        int lc[10];
        int ll[10][10];
        int td[10];
        cin >> n;
        if(n == 0) break;

        for(int i=0;i<10;i++){
            lc[i] = 0;
        }
        int town=-1;
        for(int i=0;i<n;i++){
            int a,b,c;
            cin >> a >> b >> c;

            if(a > town) town = a+1;
            if(b > town) town = b+1;
            ll[a][lc[a]] = b;
            ll[b][lc[b]] = a;
            lc[a] += 1;
            lc[b] += 1;
            ld[a][b] = ld[b][a] = c;
        }

        int minsum = INF;
        int mintown;
        //cout << "town "<< town << '\n';
        for(int i=0;i<town;i++){
            for(int j=0;j<town;j++){
                td[j] = INF;
            }
            td[i] = 0;
            while(1){
                bool changed = false;
                for(int j=0;j<town;j++){
                    for(int k=0;k<lc[j];k++){
                        if(td[ll[j][k]] + ld[ll[j][k]][j] < td[j]){
                            td[j] = td[ll[j][k]] + ld[ll[j][k]][j];
                            changed = true;
                        }
                    }
                }
                if(!changed) break;
            }
            int sum=0;
            for(int j=0;j<town;j++){
                sum += td[j];
            }
            cout << sum << '\n';
            if(sum < minsum){
                minsum = sum;
                mintown = i;
            }
        }
        cout << mintown << ' ' << minsum << '\n';
    }
    return 0;
}
