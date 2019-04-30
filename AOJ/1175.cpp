#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int cn[4];
int id[4][6];
unsigned int over_bits[24];

struct Data {
    double x, y, r;
    int c;
};

char memo[1<<25];

int dfs(unsigned int bits) {
    if(memo[bits] >= 0) return memo[bits];
    int mmax = 0;
    for(int i=0;i<4;i++){
        int removable[6];
        int count = 0;
        for(int j=0;j<cn[i];j++){ 
            int k = id[i][j];
            if((bits & (1 << k)) != 0 && (bits & over_bits[k]) == 0){
                removable[count] = k;
                count++;
            }
        }

        if(count < 2){
            continue;
        }else{
            for(int j=0;j<count;j++){
                for(int k=j+1;k<count;k++){
                    unsigned int one = (1 << removable[j]);
                    unsigned int two = (1 << removable[k]);
                    mmax = max(mmax, 2 + dfs(bits ^ (one | two)));
                }
            }
        }
    }
    return memo[bits] = mmax;
}

int main() {
    while(true){
        // input
        int n;cin >> n;
        if(n == 0) break;

        for(int i=0;i<4;i++) cn[i] = 0;
        for(int i=0;i<(1<<25);i++) memo[i] = -1;

        unsigned int bits = 0;
        vector<Data> data;
        for(int i=0;i<n;i++){
            double x, y, r;
            int c;
            cin >> x >> y >> r >> c;
            c--;
            id[c][cn[c]++] = i;
            data.push_back({x, y, r, c});

            over_bits[i] = 0;
            bits = bits << 1 | 1;
        }

        // 前処理
        for(int i=0;i<n;i++){
            int c = data[i].c;
            for(int j=i+1;j<n;j++){
                double dx = data[j].x - data[i].x;
                double dy = data[j].y - data[i].y;
                if(data[i].r + data[j].r > sqrt(dx*dx + dy*dy)){
                    // i is over j
                    over_bits[j] |= 1 << i;
                }
            }
        }
        
        // output
        printf("%d\n", dfs(bits));
    }
    return 0;
}
