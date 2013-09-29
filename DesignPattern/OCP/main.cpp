#include "../common.h"
#include "OpenClosePrinciple.h"

void ExploreOpenClosePrinciple(void){
  //OpenClose Principle example (refer to README.md) 
  ShapeManager* pSM = new ShapeManager();
  for (int i = 0; i < 3; i++) {
        int choice = 0;
        cout<<"0.Circle 1.Rectangle 2.Triangle:"<<endl;
        cin>>choice;
        Shape* pShape = NULL;
        switch(choice)
        {
          case 0:
                pShape = new Circle(10);
            break;
          case 1:
                pShape = new Rectangle(10,20);
            break;
          case 2:
                pShape = new Triangle(10,30);
            break;
          default:
                pShape = new Shape();
            break;
        }
        pSM->showDetails(pShape);
        delete pShape;
  }
  delete pSM;
}

int
main(int argc,char** argv){
  ExploreOpenClosePrinciple();
  return 0;
}
