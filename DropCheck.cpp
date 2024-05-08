#include "DropCheck.h"
#include <cstdlib>

bool DropCheck::productReleased(){
    int randomnbr = rand()%100;
    return randomnbr>=9;

}
