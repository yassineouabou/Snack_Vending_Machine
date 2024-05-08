#ifndef AUTOMAT_H
#define AUTOMAT_H
#include<vector>
#include "Slot.h"
#include "CoinSlot.h"
#include "Clavier.h"
#include "DropCheck.h"

class Automat{
    vector<Slot*> slots;
    int numSlots;
    Slot* cached;
    int NumProductsPerSlot;
    int insertPos;
    CoinSlot coinslot;
    Clavier clavier;
    DropCheck dropcheck;
public:
    Automat(int ,int);
    ~Automat();
    bool addSlot(string,int,int,int,int);
    bool addSlot(string,int,int,int);
    Slot* searchSlot(int);
    void changeSlot(int,string,int);
    int getNumPieces(int );
    bool isAvaiable(int);
    int getPrice(int);
    bool dropSlot(int);
    void fillAll();
    void remplir(int slotId,int numProducts);
};


#endif // AUTOMAT_H
