//
// Created by noor dar yahya on 04/06/2023.
//

#ifndef UNTITLED37_LAYER_H
#define UNTITLED37_LAYER_H
#include <iostream>
using namespace std;
#include "Class.h"
class Layer {
private:
    char layer;
    Class** classes;
    int num = 3;
public:
    ~Layer();
    Layer(char layer);
    Class* getclass(int i);
    char getLayerName();
};

#endif //UNTITLED37_LAYER_H
