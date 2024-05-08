#include "CoinSlot.h"

CoinSlot::CoinSlot(){
    insertedAmount=0;
}

int CoinSlot::updateCoinAmount(){
    int Coin;
    cout << "Inserez une piece (200,100,50,20,10,5,1) ou entrez -1 pour annuler : ";
    cin >> Coin;
    if(Coin == -1)
        return -1;
    else{
        insertedAmount+= Coin;
        return insertedAmount;
    }
}

int CoinSlot::getCoinAmount(){
    return insertedAmount;
}

void CoinSlot::clear(){
    insertedAmount=0;
}

void CoinSlot::returnCoins(int price){
    int change = insertedAmount - price;
    if(change<0){
         change = insertedAmount;
    }
        cout<<"\t---------------------------------\n";
         cout << "\t|\tMonnaie retourner :     |" << endl;
        for (int i = 0; i < 7; ++i) {
            int numCoins = change / coinValues[i];
            if (numCoins > 0) {
                cout <<"\t|\t"<<numCoins << " x " << coinValues[i] << " cents\t\t|"<< endl;
                change %=coinValues[i];
            }
        }
          cout<<"\t---------------------------------\n";
}

