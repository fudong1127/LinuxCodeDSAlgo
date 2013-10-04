#include "iostream"
#include "vector"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

typedef struct __Data{
      int           nTotalVal;
      int           nNumCoins;
}Data;

class MakeChangeInterface{
  public:
    virtual void doMakeChange() = 0;
};

class GreedyApproachMakeChange : public MakeChangeInterface{
  public:
    virtual void doMakeChange(){
    
    }
};

class DynamicApproachMakeChange : public MakeChangeInterface{
  public:
    virtual void doMakeChange(){
      //TODO 
    }
};

class MakeChange{
    MakeChangeInterface* pInterface;
    MakeChange(MakeChangeInterface* pIF)
    {
       this->pInterface = pIF; 
    }
    void doMakeChange()
    {
      if(this->pInterface)
        this->pInterface->doMakeChange();
      else
        cout<<"You forgot to set the Interface!!"<<endl;
    }
};

int 
main(int argc,char** argv){
  Data* pData = new Data();
  cout<<"What is the Total amaout?"<<endl; 
  cin>>pData->nTotalVal;
  
  cout<<"How many coins are there?"<<endl; 
  cin>>pData->nNumCoins;
  
  delete pData;
  return 0;
}
