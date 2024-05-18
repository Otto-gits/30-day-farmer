#include "Tool.h"

Tool::Tool(){
    uses = 0;
}

int Tool::getUses(){
    return uses;
}

void Tool::setUses(int uses){
    this->uses = uses;
}
