#include <iostream>
#include <fstream>
using namespace std;
#include "Automat.h"

int addcoin(CoinSlot &coin,int price){
    int inserer;
     int add =0;
     inserer = coin.updateCoinAmount();
        while(inserer!=-1){
            add = coin.getCoinAmount();
            cout<<"\n\t-------------------------------------\n";
            cout <<"\t|  Le prix que vous avez saisi: "<<add<<" |"<<endl;
             cout<<"\t-------------------------------------\n";
            if(add>=price)
                return add;
            inserer = coin.updateCoinAmount();
        }
    return add;
}

bool prodReleased(DropCheck D){
    bool drop = false;
    while(!drop){
        drop = D.productReleased();
    }
    return drop;
}

int main(){
    Automat A(12,4);
    Clavier C;
    CoinSlot coin;
    DropCheck drop;
    bool isdrop;
    fstream myFile;
    myFile.open("Slots.txt",ios::in);
    if(myFile.is_open()){
        string id,nom,price,motor1,motor2;
        int line = 0;
        cout <<"---------------------------------------------------------------------------------------------------------\n";
        while(myFile>>id>>nom>>price>>motor1>>motor2){
                int id_int = stoi(id);
                int price_int = stoi(price);
                int motor1_int = stoi(motor1);
                int motor2_int = stoi(motor2);
                cout <<"|\t"<<id<<"-"<<nom<<"\t";
                cout <<price_int<<"\t";
                line++;
                if(line==3){
                    cout<<"\t|"<<endl;
                    cout <<"---------------------------------------------------------------------------------------------------------";
                    cout<<endl;
                    line=0;
                }
                if (motor2_int == 0)
                    A.addSlot(nom,id_int,price_int, motor1_int);
                else
                    A.addSlot(nom,id_int,price_int, motor1_int, motor2_int);
        }
        myFile.close();
    }
    A.fillAll();
     int id,price,add;
     id  = C.getSelection();
     while(id!=-1){
        price = A.getPrice(id);
        add = addcoin(coin,price);
        if(add<price)
            coin.returnCoins(price);
        else{
            isdrop = prodReleased(drop);
            if(isdrop){
                cout<<endl;
                A.dropSlot(id);
                cout<<endl;
                coin.returnCoins(price);
                coin.clear();
            }
        }
        id  = C.getSelection();
     }
    return 0;
}
