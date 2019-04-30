// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    string s1, s2, s3;cin >> s1 >> s2 >> s3;
    vector<int> cnt1(ALPHABET, 0), cnt2(ALPHABET, 0), cnt3(ALPHABET, 0);
    for(auto c : s1) cnt1[c-'A']++;
    for(auto c : s2) cnt2[c-'A']++;
    for(auto c : s3) cnt3[c-'A']++;

    int c1 = int(s1.size())/2;
    int c2 = c1;

    for(int i=0;i<ALPHABET;i++){
        if(cnt3[i] > cnt1[i] + cnt2[i]){
            goto NO;
        }
    }
    while(true){
        bool flag = false;
        for(int i=0;i<ALPHABET;i++){
            if(cnt3[i] > 0 && cnt1[i] > 0 && cnt2[i] == 0){
                c1 -= cnt3[i];
                cnt1[i] -= cnt3[i];
                cnt3[i] = 0;
                flag = true;
            }else if(cnt3[i] > 0 && cnt2[i] > 0 && cnt1[i] == 0){
                c2 -= cnt3[i];
                cnt2[i] -= cnt3[i];
                cnt3[i] = 0;
                flag = true;
            }
            if(cnt3[i] > 0 && cnt3[i] == cnt1[i] + cnt2[i]){
                c1 -= cnt1[i];
                c2 -= cnt2[i];
                cnt3[i] = 0;
                flag = true;
            }
            if(cnt3[i] > 0){
                if(cnt1[i] < cnt2[i] && cnt1[i] < cnt3[i]){
                    c2--;
                    cnt3[i]--;
                    flag = true;
                }
                if(cnt2[i] < cnt1[i] && cnt2[i] < cnt3[i]){
                    c1--;
                    cnt3[i]--;
                    flag = true;
                }
            }
            if(c1 < 0 || c2 < 0){
                goto NO;
            }
        }
        if(!flag) break;
    }
    

    cout << "YES" << endl;
    return 0;

NO:
    cout << "NO" << endl;
    return 0;
}
