#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

class MinProduct {
    public:
    long long findMin(vector<int> amount, int blank1, int blank2) {
        if(amount[0] >= blank1 || amount[0] >= blank2) return 0;
        long long a = 0;
        long long b = 0;
        //while(blank1 != blank2){
            //long long n = 0;
            //for(long long j=0;j<10;j++){
                //if(amount[j] > 0){
                    //amount[j]--;
                    //n = j;
                    //break;
                //}
            //}
            //a = a*10LL + n;
            //blank1--;
        //}
        while(amount[0] > 0){
            if(blank1 < blank2){
                blank1--;
            }else{
                blank2--;
            }
            amount[0]--;
        }
        if(blank1 > blank2) swap(blank1, blank2);
        for(int i=0;i<max(blank1, blank2);i++){
            if(i < blank1){
                long long n = 0;
                for(long long j=0;j<10;j++){
                    if(amount[j] > 0){
                        amount[j]--;
                        n = j;
                        break;
                    }
                }
                a = a*10LL + n;
            }
            if(i < blank2){
                long long n = 0;
                for(long long j=0;j<10;j++){
                    if(amount[j] > 0){
                        amount[j]--;
                        n = j;
                        break;
                    }
                }
                b = b*10LL + n;
            }
        }
        return a*b;
    }
};

// CUT begin
ifstream data("MinProduct.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> amount, int blank1, int blank2, long long __expected) {
    time_t startClock = clock();
    MinProduct *instance = new MinProduct();
    long long __result = instance->findMin(amount, blank1, blank2);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> amount;
        from_stream(amount);
        int blank1;
        from_stream(blank1);
        int blank2;
        from_stream(blank2);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(amount, blank1, blank2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1503572774;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "MinProduct (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
