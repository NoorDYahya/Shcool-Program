#include "Layer.h"

Layer::~Layer(){}
Layer::Layer(char layer) {
    this->layer = layer;
    this->classes = new Class * [this->num];
    for(int i = 0 ; i < num ; i++){
        classes[i] = new Class(layer,i+1);
    }
}
Class* Layer::getclass(int i) {
    return this->classes[i];
}
char Layer::getLayerName(){
    char a = layer;
    return layer;
}
