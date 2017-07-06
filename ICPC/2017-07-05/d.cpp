#include <iostream>
using namespace std;

bool i_under_j[100][100];

int cn[4];

// struct Data {
//     int id;
//     double x, y, r;
//     int c;
// }

int main() {
    while(true){
        int n;cin >> n;

        vector<Data> dat;

        unsigned int bits = 0;

        for(int i=0;i<4;i++) cn[i] = 0;

        for(int i=0;i<n;i++){
            double x, y, r;
            int c;
            cin >> x >> y >> r >> c;
            cn[c-1]++;
            // Data d = {i, x, y, t, c};
            // data.push_back(d);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

            }
        }
    }
    return 0;
}
