//
// Created by indrek on 1.04.2017.
//

#ifndef PBLOCKMAIN_MODULE_H
#define PBLOCKMAIN_MODULE_H


#include <IconBuffer.h>


class Module {

public:
    IconBuffer & icon;

    Module(IconBuffer & icon) : icon(icon) {};

};



#endif //PBLOCKMAIN_MODULE_H
