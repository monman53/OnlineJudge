#include <fstream>
#include <random>
#include <iostream>
using namespace std;

int main()
{
  // メルセンヌ・ツイスター法による擬似乱数生成器を、
  // ハードウェア乱数をシードにして初期化
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  cout << engine() << endl;
}
