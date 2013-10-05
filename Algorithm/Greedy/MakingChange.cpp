#include "iostream"
#include "vector"
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

typedef struct __SolutionSet{
      int*          pCoins;
      int           size;
}SolutionSet;

typedef struct __Data{
      int           nTotalVal;
      int           nNumCoins;
      int*          pCoins;
      SolutionSet*  pSolutionSet;
}Data;

class MakeChangeInterface{
  protected:
    virtual void DoMakeChange(Data& data)     = 0;
  
  public:
    virtual ~MakeChangeInterface(){
    }
    
    void performMakeChange(Data& data)
    {
       qsort(data.pCoins,data.nNumCoins,sizeof(int),this->compare);     
       if(data.pSolutionSet){
          if(data.pSolutionSet->pCoins){
            delete [] data.pSolutionSet->pCoins;
          }
          delete data.pSolutionSet;
       }
       data.pSolutionSet  = new SolutionSet();
       data.pSolutionSet->pCoins  = new int[data.nNumCoins];
       data.pSolutionSet->size    = 0;
       DoMakeChange(data);
    }

    static int compare(const void* num1,const void* num2){
        int nResult = 0;
        int n1 = *(int*)num1;
        int n2 = *(int*)num2;
        
        if(n1 == n2)
          nResult = 0;
        else if(n1 < n2)
          nResult = 1;
        else
          nResult = -1;

        return nResult;
    }
};

class GreedyApproachMakeChange : public MakeChangeInterface{
  public:
    virtual void DoMakeChange(Data& data){
       int sum = 0;
       for (int i = 0; i < data.nNumCoins && sum < data.nTotalVal; i++) 
       {
          int value = data.pCoins[i];
          if(value + sum > data.nTotalVal)
          {
              delete [] data.pSolutionSet->pCoins;
              data.pSolutionSet->pCoins = NULL;
              data.pSolutionSet->size = -1;
              break;
          }
          data.pSolutionSet->pCoins[i] = value;
          data.pSolutionSet->size++;
          sum = sum + value;
       }
    }
};

class DynamicApproachMakeChange : public MakeChangeInterface{
  public:
    virtual void DoMakeChange(Data& data){
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
    
    MakeChange& performMakeChange(void)
    {
      if(this->pInterface)
        this->pInterface->performMakeChange(*pData);
      else
        cout<<"You forgot to set the Interface!!"<<endl;

      return *this;
    }
    
    MakeChange& fillData(void)
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
    
        return (*this);
    }

    MakeChange& showSolution(){
        for (int i = 0; i < this->pData->pSolutionSet->size; i++) {
          cout<<this->pData->pSolutionSet->pCoins[i]<<" ";
        }
        return (*this);
    }

    ~MakeChange()
    {
        if(this->pData){
          if(this->pData->pSolutionSet){
              if(this->pData->pSolutionSet->pCoins){
                delete [] this->pData->pSolutionSet->pCoins;
                this->pData->pSolutionSet->pCoins = NULL;
              }
              delete this->pData->pSolutionSet;
              this->pData->pSolutionSet = NULL;
          }
          delete [] pData;
          pData = NULL;
        }
        if(this->pInterface){
          delete this->pInterface;
          this->pInterface = NULL;
        }
    }
};


int 
main(int argc,char** argv){
  MakeChange* pMakeChange = new MakeChange(new GreedyApproachMakeChange());
  (*pMakeChange).fillData().performMakeChange().showSolution();
  delete pMakeChange;
  return 0;
}
