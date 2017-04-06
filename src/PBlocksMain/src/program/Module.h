//
// Created by indrek on 1.04.2017.
//

#ifndef PBLOCKMAIN_MODULE_H
#define PBLOCKMAIN_MODULE_H


#include "src/icons/Icon.h"


class Module {

public:
    Icon & icon;

    Module(Icon & icon) : icon(icon) {};

};



#endif //PBLOCKMAIN_MODULE_H
