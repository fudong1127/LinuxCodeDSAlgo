#include "../common.h"
#include "OpenClosePrinciple.h"

void ExploreOpenClosePrinciple(void){
  //OpenClose Principle example (refer to README.md) 
  ShapeManager* pSM = new ShapeManager();
  Shape* pShape1 = new Circle(10);
  Shape* pShape2 = new Rectangle(10,20);
  Shape* pShape3 = new Triangle(10,30);
  pSM->showDetails(pShape1);
  pSM->showDetails(pShape2);
  pSM->showDetails(pShape3);
  delete pShape1;
  delete pShape2;
  delete pShape3;
  delete pSM;
}

int
main(int argc,char** argv){
  ExploreOpenClosePrinciple();
  return 0;
}
