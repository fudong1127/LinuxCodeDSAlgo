#include "../common.h"
#include "OpenClosePrinciple.h"

void Shape::showDetails(){
    cout<<"Nothing to show!!...go away!!"<<endl;
}


void Circle::showDetails(){
    cout<<"i am just a Circle!!..my parameter is: "<<this->radius<<endl;
}

void Rectangle::showDetails(){
    cout<<"i am just a Rectangle!!..my prameters are: "<<this->length<<" "<<this->breadth<<endl;
}

void Triangle::showDetails(){
    cout<<"i am just a Triangle!!..my prameters are: "<<this->height<<" "<<this->base<<endl;
}
