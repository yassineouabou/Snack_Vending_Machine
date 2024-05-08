#include "Slot.h"

Slot::Slot(int slotId,string productname,int p){

    id=slotId;
    productName=productname;
    price=p;
}

Slot::~Slot(){
}

string Slot::getProductName(){
return productName;
}

void Slot::setProductName(string name){
    productName = name;
}

int Slot::getNumProducts(){
    return numProducts;
}
void Slot::setNumProducts(int num){
    numProducts = num;
}

int Slot::getPrice(){
    return price;
}

void Slot::setPrice(int p){
    price=p;
}
int Slot::getId(){
    return id;
}

void Slot::setId(int Id){
id =Id;
}

SmallSlot::SmallSlot(int slotId,string productName,int price,int motor1Id,int motor2Id):Slot(slotId,productName,price){
    moteur1= new Moteur(motor1Id);
}

void SmallSlot::drop()const{
    moteur1->Trigger();
     cout <<"\t====>\t"<<productName<<" livre a partir du logement "<<id<<endl;
}

WideSlot::WideSlot(int slotId,string productName,int price,int motor1Id,int motor2Id):Slot(slotId,productName,price){
    moteur1= new Moteur(motor1Id);
    moteur2 = new Moteur(motor2Id);
}

void WideSlot::drop()const{
    moteur1->Trigger();
    moteur2->Trigger();
    cout <<"\n\t====>\t"<<productName<<" livre a partir du logement "<<id<<endl;
}
