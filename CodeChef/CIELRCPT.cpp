#include <stdio.h> 

int menu[] = {1,2,4,8,16,32,64,128,256,512,1024,2048};
int nTestCase = 0;

void 
Ciel_and_Receipt(void){
    scanf("%d",&nTestCase);
    
    while(nTestCase > 0){
       int Value = 0;
       int index = 11;
       int cnt = 0;
       scanf("%d",&Value);
     
       while((index >= 0) && (Value > 0)){
              if(((index == 11)&&(Value > menu[index])) || 
                  (Value == menu[index]) || 
                  ((index<=11)&&(Value > menu[index])&&
                   (Value < menu[index+1]))){
                                  cnt++;
                                  Value -= menu[index];
                                  index = 11;       
              }
              else
                 index --;
        }//end while
        printf("%d\n",cnt);
        nTestCase--;
    }//end while
}

int main(){
    Ciel_and_Receipt();
     return 0;
}
