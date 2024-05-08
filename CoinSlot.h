#include <iostream>
#include <vector>
using namespace std;

class CoinSlot{
    int insertedAmount;
    const vector<int> coinValues={200,100,50,20,10,5,1};
public:
    CoinSlot();
    int updateCoinAmount();
    int getCoinAmount();
    void clear();
    void returnCoins(int);

};

