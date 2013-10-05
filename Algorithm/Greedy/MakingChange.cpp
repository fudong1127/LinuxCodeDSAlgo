#include "iostream"
#include "vector"
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

typedef struct __Data{
      int           nTotalVal;
      int           nNumCoins;
      int*          pCoins;
}Data;

class MakeChangeInterface{
  public:
    virtual void doMakeChange(Data& data) = 0;

    int compare(const void* num1,const void* num2){
        int nResult = 0;
        return nResult;
    }
};

class GreedyApproachMakeChange : public MakeChangeInterface{
  public:
    virtual void doMakeChange(Data& data){
       qsort(data.pCoins,data.nNumCoins,sizeof(int),this->compare);     
    }
};

class DynamicApproachMakeChange : public MakeChangeInterface{
  public:
    virtual void doMakeChange(Data& data){
    }
};

class MakeChange{
  private:
    MakeChangeInterface* pInterface;
    Data* pData;
  public:
    MakeChange(MakeChangeInterface* pIF)
    {
       this->pInterface = pIF;
       this->pData      = new Data(); 
    }
    
    void doMakeChange(void)
    {
      if(this->pInterface)
        this->pInterface->doMakeChange(*pData);
      else
        cout<<"You forgot to set the Interface!!"<<endl;
    }
    
    void fillData(void)
    {
        cout<<"What is the Total amaout?"<<endl; 
        cin>>pData->nTotalVal;
  
        cout<<"How many coins are there?"<<endl; 
        cin>>pData->nNumCoins;

        pData->pCoins = new int[pData->nNumCoins];
        cout<<"Enter the coin values:"<<endl; 

        for (int i = 0; i < pData->nNumCoins; i++) 
        {
            cin>>(pData->pCoins)[i];
        }
    }

    ~MakeChange()
    {
        if(this->pData)
          delete [] pData;
        if(this->pInterface)
          this->pInterface = NULL;
    }
};


int 
main(int argc,char** argv){
  MakeChange* pMakeChange = new MakeChange(new GreedyApproachMakeChange());
  pMakeChange->fillData();
  delete pMakeChange;
  return 0;
}
