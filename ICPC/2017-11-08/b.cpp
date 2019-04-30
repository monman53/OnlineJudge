#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> C;

int score(vector<C> c) {
    sort(c.begin(), c.end());
    set<char> s;
    for(int i=0;i<5;i++){
        s.insert(c[i].second);
    }
    int kinds = s.size();

    bool seq_flag1 = true;
    for(int i=1;i<5;i++){
        if(c[i-1].first+1 != c[i].first){
            seq_flag1 = false;
        }
    }
    bool seq_flag2 = true;
    for(int i=0;i<4;i++){
        if(c[i].first != i+2){
            seq_flag2 = false;
        }
    }
    if(c[4].first != 14){
        seq_flag2 = false;
    }

    bool seq_flag = seq_flag1 | seq_flag2;

    int sum = 0;
    for(int i=0, p=1;i<5;i++, p*=15){
        sum += c[i].first*p;
    }

    // Straight flush
    if(kinds == 1 && seq_flag){
        if(seq_flag2){
            return 80000000 + 5;
        }else{
            return 80000000 + c[4].first;
        }
    }

    // Four of a kind
    if(c[0].first == c[3].first){
        return 70000000 + c[0].first*15 + c[4].first;
    }
    if(c[1].first == c[4].first){
        return 70000000 + c[1].first*15 + c[0].first;
    }

    // Full house
    if(c[0].first == c[2].first && c[3].first == c[4].first){
        return 60000000 + c[0].first*15 + c[3].first;
    }
    if(c[0].first == c[1].first && c[2].first == c[4].first){
        return 60000000 + c[2].first*15 + c[0].first;
    }

    // Flush
    if(kinds == 1){
        return 50000000 + sum;
    }

    // Straight
    if(seq_flag){
        if(seq_flag2){
            return 40000000 + 5;
        }else{
            return 40000000 + c[4].first;
        }
    }

    // Three of a kind
    if(c[0].first == c[2].first){
        return 30000000 + c[0].first*15*15 + c[4].first*15 + c[3].first;
    }
    if(c[1].first == c[3].first){
        return 30000000 + c[1].first*15*15 + c[4].first*15 + c[0].first;
    }
    if(c[2].first == c[4].first){
        return 30000000 + c[2].first*15*15 + c[1].first*15 + c[0].first;
    }

    // Two pairs
    if(c[0].first == c[1].first && c[2].first == c[3].first){
        return 20000000 + c[2].first*15*15 + c[0].first*15 + c[4].first;
    }
    if(c[0].first == c[1].first && c[3].first == c[4].first){
        return 20000000 + c[3].first*15*15 + c[0].first*15 + c[2].first;
    }
    if(c[1].first == c[2].first && c[3].first == c[4].first){
        return 20000000 + c[3].first*15*15 + c[1].first*15 + c[0].first;
    }

    // One pair
    if(c[0].first == c[1].first){
        return 10000000 + c[0].first*15*15*15 + c[4].first*15*15 + c[3].first*15 + c[2].first;
    }
    if(c[1].first == c[2].first){
        return 10000000 + c[1].first*15*15*15 + c[4].first*15*15 + c[3].first*15 + c[0].first;
    }
    if(c[2].first == c[3].first){
        return 10000000 + c[2].first*15*15*15 + c[4].first*15*15 + c[1].first*15 + c[0].first;
    }
    if(c[3].first == c[4].first){
        return 10000000 + c[3].first*15*15*15 + c[2].first*15*15 + c[1].first*15 + c[0].first;
    }

    // High card
    return sum;
}

C str2card(string s) {
    char suit = s[0];
    int rank = s[1] - '0';
    if(s[1] == 'A') rank = 14;
    if(s[1] == 'K') rank = 13;
    if(s[1] == 'Q') rank = 12;
    if(s[1] == 'J') rank = 11;
    if(s[1] == 'T') rank = 10;
    return {rank, suit};
}

int main() {
    while(true){
        //vector<C> v;
        //for(int i=0;i<5;i++){
            //string s;cin >> s;
            //v.push_back(str2card(s));
        //}
        //cout << score(v) << endl;
        
        // input
        vector<C> v[2];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                string s;cin >> s;
                if(s == "#") return 0;
                v[i].push_back(str2card(s));
            }
        }
        for(int i=0;i<3;i++){
            string s;cin >> s;
            v[0].push_back(str2card(s));
            v[1].push_back(str2card(s));
        }

        vector<C> other;
        char c[4] = {'S', 'H', 'D', 'C'};
        for(int rank=2;rank<=14;rank++){
            for(int j=0;j<4;j++){
                bool flag = true;
                for(int k=0;k<2;k++){
                    for(int l=0;l<5;l++){
                        if(v[k][l] == C{rank, c[j]}) flag = false;
                    }
                }

                if(flag){
                    other.push_back({rank, c[j]});
                }
            }
        }

        int n = other.size();
        int a = 0, b = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<C> vv[2];
                int mmax[2] = {0, 0};
                for(int k=0;k<2;k++){
                    vv[k] = v[k];
                    vv[k].push_back(other[i]);
                    vv[k].push_back(other[j]);

                    sort(vv[k].begin(), vv[k].end());

                    vector<int> index = {0, 0, 1, 1, 1, 1, 1};

                    do{
                        vector<C> vvv;
                        for(int l=0;l<7;l++){
                            if(index[l] == 1){
                                vvv.push_back(vv[k][l]);
                            }
                        }
                        int s = score(vvv);
                        if(mmax[k] < s){
                            mmax[k] = s;
                        }
                    }while(next_permutation(index.begin(), index.end()));
                }
                if(mmax[0] > mmax[1]){
                    a++;
                }else{
                    b++;
                }
            }
        }
        printf("%0.9lf\n", a/double(a+b));
    }
    return 0;
}
