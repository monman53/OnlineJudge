#include<bits/stdc++.h>
using namespace std;

int n;
double x[200], y[200];
int ans[200];

inline uint32_t xor128(void){
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123; 
    const uint32_t t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

inline double energy() {
    double mean = 0;
    for(int k=0;k<n;k++){
        int i = ans[k];
        int j = ans[(k+1)%n];
        double dx = x[j] - x[i];
        double dy = y[j] - y[i];
        double d = sqrt(dx*dx + dy*dy);
        mean += d;
    }
    mean /= n;

    double variance = 0;
    for(int k=0;k<n;k++){
        int i = ans[k];
        int j = ans[(k+1)%n];
        double dx = x[j] - x[i];
        double dy = y[j] - y[i];
        double d = sqrt(dx*dx + dy*dy);
        variance += (d-mean)*(d-mean);
    }
    variance /= n;

    return variance;
}

inline double p(){
    return double(xor128())/UINT32_MAX;
}

inline double probability(double e_prev, double e_next, double t) {
    if(e_prev >= e_next){
        return 1;
    }else{
        return exp((e_prev-e_next)/t);
        //return 1;
        //return 0; // hill climbing
    }
}

int main() {
    clock_t t_start = clock();
    // input 
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
        ans[i] = i;
    }

    // search
    double time = 0;
    double alpha = 0.1;
    //int cnt = 0;
    while(true){
        //cnt++;
        clock_t t_now = clock();
        time = double(t_now-t_start)/CLOCKS_PER_SEC/2;
        if(time > 0.95){
            break;
        }
        double e_prev = energy();
        int i = xor128()%n;
        int j = xor128()%n;
        swap(ans[i], ans[j]);
        double e_next = energy();
        if(p() <= probability(e_prev, e_next, pow(alpha, time))){
            //cout << e_next << endl;
        }else{
            swap(ans[i], ans[j]);
        }
    }
    //cout << cnt << endl;

    // output
    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }
    return 0;
}
