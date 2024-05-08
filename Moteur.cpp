#include "Moteur.h"


Moteur::Moteur(int idmot){
    id=idmot;
}

Moteur::~Moteur(){}

void Moteur::Trigger(){
    if(id){
        cout<<"\t  ________________________________\n";
        cout <<"\t  |  Moteur ID = "<<id<<" est active   |\n\n";
    }
}
void Moteur::setIdmoteur(int I){
    id = I;
}
