#include <bits/stdc++.h>
using namespace std;

const double max_time = 2;
int n;
double x[200], y[200];

inline uint32_t xor128(void){
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123; 
    const uint32_t t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

inline double unifom() {
    return double(xor128())/UINT32_MAX;
}

inline double energy(vector<int> &state) {
    vector<double> d(n);
    double mean = 0;
    for(int i=0;i<n;i++){
        const int a = state[i];
        const int b = state[(i+1)%n];
        const double sx = x[a];
        const double sy = y[a];
        const double tx = x[b];
        const double ty = y[b];
        const double dx = tx - sx;
        const double dy = ty - sy;
        d[i] = dx*dx + dy*dy;
        mean += d[i];
    }
    mean /= n;
    double res = 0;
    for(int i=0;i<n;i++){
        res += (d[i]-mean)*(d[i]-mean);
    }
    return res;
}

double sum, sum2, mu;

void init(vector<int> &state) { // {{{
    vector<double> d(n);
    for(int i=0;i<n;i++){
        const int a = state[i];
        const int b = state[(i+1)%n];
        const double sx = x[a];
        const double sy = y[a];
        const double tx = x[b];
        const double ty = y[b];
        const double dx = tx - sx;
        const double dy = ty - sy;
        d[i] = dx*dx + dy*dy;
    }
    sum = 0;
    sum2 = 0;
    for(int i=0;i<n;i++){
        sum += d[i];
        sum2 += d[i]*d[i];
    }
    mu = sum/n;
}// }}}

inline void func(vector<int> &state, int i, int flag) { // {{{
    const int a = state[(i-1+n)%n];
    const int b = state[(i+1+n)%n];
    const double dxa = x[a] - x[state[i]];
    const double dya = y[a] - y[state[i]];
    const double dxb = x[b] - x[state[i]];
    const double dyb = y[b] - y[state[i]];
    const double da = dxa*dxa + dya*dya;
    const double db = dxb*dxb + dyb*dyb;

    if(flag){
        sum += da + db;
        sum2 += da*da + db*db;
        mu = sum/n;
    }else{
        sum -= da + db;
        sum2 -= da*da + db*db;
        mu = sum/n;
    }
}// }}}


inline void my_swap(vector<int> &state, int i, int j) {
    func(state, i, 0);
    func(state, j, 0);
    swap(state[i], state[j]);
    func(state, i, 1);
    func(state, j, 1);
}

inline double fast_energy() {
    return sum2-2*sum*mu+mu*mu*n;
}

int main() {
    clock_t start = clock();

    // input
    cin >> n;
    vector<int> state(n);
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
        state[i] = i;
    }
    init(state);

    // search
    //double prev_e = energy(state);
    double prev_e = fast_energy();
    double best_e = prev_e;
    auto best_state = state;
    double time = 0;
    double T = 0;
    double dt = 0.00001;    // 10万
    double alpha = 0.00001;
    int cnt = 0;
    double pow_ = 1;
    while(true){
        // time check
        if(cnt%1000 == 0){
            clock_t now = clock();
            if(double(now-start)/CLOCKS_PER_SEC > max_time-0.1){
                break;
            }
            if(double(now-start)/CLOCKS_PER_SEC > time){
                T = double(now-start)/CLOCKS_PER_SEC;
                pow_ = pow(alpha, T/max_time)*1000000000.0;
                //printf("%lf %lf\n", pow_, best_e);
                //printf("%lf\n", best_e);
                time += dt;
            }
        }
        cnt++;

        // sa
        int a = xor128()%n;
        int b = xor128()%n;
        my_swap(state, a, b);
        const double next_e = fast_energy();
        const double p = exp((prev_e-next_e)/pow_);
        if(next_e <= prev_e || unifom() < p){
        //if(next_e <= prev_e){
            prev_e = next_e;
            if(next_e < best_e){
                printf("%lf\n", best_e);
                best_e = next_e;
                best_state = state;
            }
        }else{
            my_swap(state, a, b);
        }
    }

    auto ans = best_state;

    // output
    for(int i=0;i<n;i++){
        //cout << ans[i] << endl;
    }

    return 0;
}
