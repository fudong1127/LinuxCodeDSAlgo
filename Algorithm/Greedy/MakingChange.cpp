#include "iostream"
#include "vector"
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

class SolutionSet{
  public:
      bool          isSol;
      int*          pCoins;
      int           size;
      
      SolutionSet(int num)
      {
          this->isSol   = false;
          this->size    = 0;
          this->pCoins  = new int[num];
      }
      
      ~SolutionSet()
      {
        if(pCoins)
        {
          delete [] pCoins;
          pCoins = NULL;
        }
        size    = -1;
        isSol   =  false;
      }
};

class Data{
  public:
      int           nTotalVal;
      int           nNumCoins;
      int*          pCoins;
      SolutionSet*  pSolutionSet;

      void InitSolution()
      {
           if(pSolutionSet)
              delete pSolutionSet;
           pSolutionSet = NULL;
           pSolutionSet  = new SolutionSet(this->nNumCoins);
      }
     
      Data(int TV,int nNC)
      {
          this->nTotalVal     = TV;
          this->nNumCoins     = nNC;
          this->pCoins        = new int[this->nNumCoins];
          this->pSolutionSet  = NULL;
      }
     
      ~Data()
      {
        if(pCoins)
        {
          delete [] pCoins;
          pCoins = NULL;
        }
        if(pSolutionSet)
        {
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
       DoMakeChange(data);
    }

    static int compare(const void* num1,const void* num2)
    {
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
    virtual void DoMakeChange(Data& data)
    {
       data.InitSolution();
       int sum = 0;
       for (int i = 0; i < data.nNumCoins && sum < data.nTotalVal; i++) 
       {
          int value = data.pCoins[i];
          if(value + sum > data.nTotalVal)
          {
              data.pSolutionSet->isSol = false;
              break;
          }
          data.pSolutionSet->isSol     = true;
          data.pSolutionSet->pCoins[i] = value;
          data.pSolutionSet->size++;
          sum = sum + value;
       }
    }
};

class DynamicApproachMakeChange : public MakeChangeInterface{
  public:
    virtual void DoMakeChange(Data& data)
    {
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
       this->pData      = NULL; 
    }
    
    MakeChange& performMakeChange(void)
    {
      if(this->pInterface && pData)
        this->pInterface->performMakeChange(*pData);
      else
        cout<<"Check the parameters you are passing!!"<<endl;

      return *this;
    }
    
    MakeChange& fillData(void)
    {
        int TV = 0;
        cout<<"What is the Total amaout?"<<endl; 
        cin>>TV;
  
        int nNC = 0;
        cout<<"How many coins are there?"<<endl; 
        cin>>nNC;

        if(pData)
        {
          delete pData;
          pData = NULL;
        }
        pData = new Data(TV,nNC);
        cout<<"Enter the coin values:"<<endl; 
        for (int i = 0; i < pData->nNumCoins; i++) 
        {
            cin>>(pData->pCoins)[i];
        }
    
        return (*this);
    }

    MakeChange& showSolution()
    {
      if(this->pData->pSolutionSet->isSol)
      {  
        for (int i = 0; i < this->pData->pSolutionSet->size; i++) 
        {
          cout<<this->pData->pSolutionSet->pCoins[i]<<" ";
        }
      }
      return (*this);
    }

    ~MakeChange()
    {
        if(pData)
        {
          delete pData;
          pData = NULL;
        }
        
        if(this->pInterface)
        {
          delete this->pInterface;
          this->pInterface = NULL;
        }
    }
};


int 
main(int argc,char** argv){
  MakeChange* pMakeChange = new MakeChange(new GreedyApproachMakeChange());
  (*pMakeChange).fillData().performMakeChange().showSolution();
  (*pMakeChange).performMakeChange().showSolution();
  (*pMakeChange).showSolution();
  delete pMakeChange;
  return 0;
}
