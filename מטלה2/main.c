#include <stdio.h>
#include "myBank.h"

int main(){
char c=0;;

while(c !='E')
{ 
printf("O -Open Account\n");
printf("B -Balance Inquiry\n");
printf("D -Deposit\n");
printf("W -Withdrawal\n");
printf("C -Close Account\n");
printf("I -Interest\n");
printf("P -Print\n");
printf("E -Exit\n");
scanf(" %c",&c);

switch(c)
    {
        case 'O':
            create();
            break;
        case 'B':
            Balance();
            break;
        case 'D':
            deposit();
            break;
        case 'W':
            withdraw();
            break;
        case 'C':
           close();
          break;
        case 'I':
           Interest();
           break;
        case 'P':
            print();
            break;
        //operator doesn't match any case constant /
        case 'E':
        closeAll();
        
         return 0;
        default:
            printf("Error! operator is not correct\n");
            break;
    }

}
    
    return 0;
}