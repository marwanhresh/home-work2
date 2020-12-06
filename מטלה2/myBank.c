#include <stdio.h>
#include "myBank.h"
double ServicePoint[SIZE][2]={0};

int isAccount(int num)
{
     if((num<ID) || (num>(ID+SIZE)))
    {
        printf("The account number is illegal\n ");
        return 0;
    }
      if(!(int)ServicePoint[num-ID][COL0])
    {
        printf("Account is not exist");
        return 0;
    }
    return 1;
}
void create(){
    double sum=0;
   
        for (int i = 0; i < SIZE; i++)
        {
            if((int)ServicePoint[i][COL0]==0)
            {
                 printf("Enter your amount?\n");
                 if(!scanf("%lf",&sum))
                 {
                        printf("invalid input\n");
                        return;
                 }
                  
                      if(sum<0)
                  {
                      printf("invalid input\n");
                      return;
                  }   
                  int tmp= (int)(sum*100);
                  sum=(double)(tmp)/100;
                ServicePoint[i][COL0] = COL1;
                ServicePoint[i][COL1] = sum;
                printf("Your account number is %d\n",(i+ID));
                return;
            }
        }
        printf("All the accounts are created \n"); 
}

void Balance()
{
    int accNum=0;
    printf("Enter your account number :");
    if(scanf(" %d",&accNum)!=1) 
    {
        printf("ERR,invalid input\n");
        return;
    }
    if(!isAccount(accNum)) {return;}
    accNum-=ID;
    if(ServicePoint[(accNum)][COL0])
    {
        printf("yours balance is:%.2lf\n",ServicePoint[(accNum)][1]);
        return;
    }
        printf("this account is closed\n");
        return;
}
void deposit()
{
  int accNum=0;
  double sum=0;
  printf("Enter your account number \n");
 if(!scanf("%d",&accNum)) 
 {
        printf("invalid input\n");
        return;
 }
   if(!isAccount(accNum)) return;
     accNum=accNum-ID;
    printf("Deposit amount");
    if(!scanf("%lf",&sum)) 
    {
        printf("invalid input\n");
        return;
    }
      if(sum<=0) 
       {
         printf("Invalid input\n");
         return;  
          }
   ServicePoint[accNum][COL1] += sum;
        printf("Your new balance is: %.2lf\n",ServicePoint[accNum][COL1]);
        return ;
}

void withdraw()
{
  int accNum=0;
  double sum=0;
  printf("Enter your account number \n");
  if(scanf("%d",&accNum)!=1) 
  {
      printf("Invalid input\n");
      return;
  }
  if(!isAccount(accNum)) return;
  accNum-=ID;
    printf("apply Withdraw amount:");
    if(scanf("%lf",&sum)!=1)  
    {
        printf("invalid input\n");
        return;
    }
      if(sum<=0)  {
         printf("invalid input\n");
          return;
                  }
    if(sum<ServicePoint[accNum][COL1]) 
   {
       ServicePoint[accNum][COL1] -= sum;
        printf("new balance is: %.2lf\n",ServicePoint[accNum][COL1]);
        return ;
   }
   printf("Withdrow is not allowed\n");

}
void Interest()
{ 
    double interest=0;
    printf("Enter the Insterest \n");
    if(scanf("%lf",&interest)!=1) 
    {
        printf("invalid input\n");
        return;
    }
    if(interest<=0)
    {
        printf("ERR,the interest should be bigger then zero\n");
        return;
    }
    for(int i=0;i<SIZE;i++)
    {
        if( ServicePoint[i][COL0])
       { 
           ServicePoint[i][1]=ServicePoint[i][COL1]*(interest/100);
       }
    }
}
void close()
{
    int accNum=0;
    printf("Enter your account number :");
      if(scanf("%d",&accNum)!=1) 
  {
      printf("invalid input\n");
      return;
  }
    if(!isAccount(accNum)) {return;}
    accNum-=ID;
    if(!ServicePoint[accNum][COL0])
    {
        printf("Account has been closed\n");
        return;
    }
    if(ServicePoint[accNum][COL1]>0)
    {
        printf("There is %lf in this account ",ServicePoint[accNum][COL1]);
    }
    ServicePoint[accNum][COL1]=0;
        ServicePoint[accNum][COL0]=0;
    }
void print()
{
   int j=1;
    for(int i=0;i<SIZE;i++)
    {
        if(ServicePoint[i][COL0])
        {
            printf( "%d Number account : %d ",j,(i+ID));
            printf(" There is %.2lf in the account\n",ServicePoint[i][COL1]);
            j++;
        }
    }
    if(j==1)
    {
        printf("There's no account open\n");
    }

}
void closeAll()
{ 
  printf("All accounts are closed");
}