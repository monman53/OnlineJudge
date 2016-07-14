// Prime
//  void Prime::sieve()         エラトステネスで篩をかける
//  bool Prime::is_prime(int n) nは素数? (これを実行する前にPrime::sieve()を実行する必要がある)
// depends on
#include <cstring>  // for memset
#define Prime_N_MAX 10000
class Prime{    // {{{
public:
    static bool is_prime_[Prime_N_MAX];

    Prime(){
        sieve();
    }

    // エラトステネスの篩でis_prime_を作成
    static void sieve(){
        std::memset(is_prime_, true, sizeof(is_prime_));
        is_prime_[0] = is_prime_[1] = false;
        for(int i=2;i<Prime_N_MAX;i++){
            if(is_prime_[i]){
                for(int j=2;i*j<Prime_N_MAX;j++){
                    is_prime_[i*j] = false;
                }
            }
        }
    }

    static bool is_prime(int n){
        if(n < 0 || n >= Prime_N_MAX){
            return false;
        }else{
            return is_prime_[n];
        }
    }
};
bool Prime::is_prime_[Prime_N_MAX]; // }}}
