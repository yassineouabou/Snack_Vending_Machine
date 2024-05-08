#include "Clavier.h"

int Clavier::getSelection(){
    int slotId;
    cout << " saisir le numero de l emplacement du produit ou -1 pour annuler : ";
    cin >>slotId;
    return slotId;
}
