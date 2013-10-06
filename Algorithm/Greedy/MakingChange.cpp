#include "iostream"
#include "vector"
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

class SolutionSet{
  public:
      int*          pCoins;
      int           size;
      SolutionSet(int num){
          this->size    = 0;
          this->pCoins  = new int[num];
      }
      ~SolutionSet(){
        if(pCoins){
          delete [] pCoins;
          pCoins = NULL;
        }
        size = -1;
      }
};

class Data{
  public:
      int           nTotalVal;
      int           nNumCoins;
      int*          pCoins;
      SolutionSet*  pSolutionSet;
      ~Data(){
        if(pCoins){
          delete [] pCoins;
          pCoins = NULL;
        }
        if(pSolutionSet){
          delete pSolutionSet;
          pSolutionSet = NULL;
        }
      }
};

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
          delete data.pSolutionSet;
       }
       data.pSolutionSet  = new SolutionSet(data.nNumCoins);
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
              delete data.pSolutionSet;
              data.pSolutionSet = NULL;
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

        if(pData->pCoins)
         delete pData->pCoins;

        pData->pCoins = new int[pData->nNumCoins];
        cout<<"Enter the coin values:"<<endl; 

        for (int i = 0; i < pData->nNumCoins; i++) 
        {
            cin>>(pData->pCoins)[i];
        }
    
        return (*this);
    }

    MakeChange& showSolution(){
      if(this->pData->pSolutionSet){  
        for (int i = 0; i < this->pData->pSolutionSet->size; i++) {
          cout<<this->pData->pSolutionSet->pCoins[i]<<" ";
        }
      }
      return (*this);
    }

    ~MakeChange()
    {
        if(pData){
          delete pData;
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
