#include "Automat.h"

Automat::Automat(int numslots, int numproduct) {
    numSlots = numslots;
    NumProductsPerSlot = numproduct;
    slots.reserve(numSlots);
}

Automat::~Automat() {
    for (Slot* slot : slots) {
        delete slot;
    }
    slots.clear();
}

bool Automat::addSlot(string Productname, int slotId, int price, int moteur1Id, int Moteur2Id) {
    if (int(slots.size()) < numSlots) {
        Slot* wideslot = new WideSlot(slotId, Productname, price, moteur1Id, Moteur2Id);
        slots.push_back(wideslot);
        return true;
    }
    else
        return false;
}

bool Automat::addSlot(string Productname, int slotId, int price, int moteur1Id){
    if (int(slots.size()) < numSlots) {
        Slot* smallslot = new SmallSlot(slotId, Productname, price, moteur1Id,0);
        slots.push_back(smallslot);
        return true;
    }
    else
        return false;
}

Slot* Automat::searchSlot(int slotId) {
    if (cached != nullptr && cached->getId() == slotId) {
        return cached;
    } else {
        for (Slot* slot : slots) {
            if (slot->getId() == slotId) {
                cached = slot;
                return slot;
            }
        }
        return nullptr;
    }
}

void Automat::changeSlot(int slotId, string name, int price) {
    Slot *S = searchSlot(slotId);
    if (S->getId() == slotId) {
        S->setProductName(name);
        S->setPrice(price);
        return;
    }
    else
    cout << "Slot non trouvé !" << endl;
}

int Automat::getNumPieces(int slotId) {
            return searchSlot(slotId)->getNumProducts();
}

bool Automat::isAvaiable(int slotId) {

    if (searchSlot(slotId)->getId() == slotId) {
        return true;
    }
    else
    return false;
}

int Automat::getPrice(int slotId) {
    Slot* S = searchSlot(slotId);
            return S->getPrice();

}

bool Automat::dropSlot(int slotId) {
    Slot* S = searchSlot(slotId);
    if(S){
        S->drop();
        return true;
    }
    else
        return false;
}

void Automat::fillAll() {
    for (Slot* slot : slots) {
        slot->setNumProducts(NumProductsPerSlot);
    }
}

void Automat::remplir(int slotId, int numProducts) {
        searchSlot(slotId)->setNumProducts(numProducts);
}
