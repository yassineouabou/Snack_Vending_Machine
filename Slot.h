#include "Moteur.h"

class Slot{
    protected:
    string productName;
    int id;
    int numProducts;
    int price;
public:
    Slot(int=0,string="",int=0);
    ~Slot();
    virtual void drop()const = 0;
    int getPrice();
    void setPrice(int p);
    int getNumProducts();
    void setNumProducts(int);
    int getId();
    void setId(int);
    string getProductName();
    void setProductName(string);
};

class SmallSlot:public Slot{
    Moteur *moteur1;
public:
    SmallSlot(int,string,int,int,int);
    void drop()const;
};

class WideSlot:public Slot{
    Moteur *moteur1,*moteur2;
public:
    WideSlot(int,string,int,int,int);
    void drop()const;
};


