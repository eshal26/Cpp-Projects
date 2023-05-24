#include<stdio.h>
#include<stdlib.h>
int main()
{
printf("Welcome to STATE BANK OF PAKISTAN\n");
int i,j,k,pin,balance,option,amount,amount1,amount2,x,npin,rpin,y,z;
pin=6897;
balance=150000;
for(i=0;i<3;i++)
{
printf("Please enter 4 digit pin : ");
scanf("%d",&pin);
if(pin==6897)
{
break;
}
else
{
printf("Incorrect pin, try again!\n");
}
}
for(; ;)
{
printf("Main menu :\n");
printf("1.Amount Deposit\n2.Balance Enquiry\n3.Amount Withdrawal\n4.ChangePin\n5.Exit\n");
printf("Choose your option : ");
scanf("%d",&option);
if(option==1)
{
printf("Amount Deposit\n");
for(j=1;j<8;j++)
{
printf("Enter your amount that must be greater than 1000 and a multiple of 500\n");
scanf("%d",&amount1);
if(amount1>1000&&amount1%500==0)
{
printf("Your amount is deposited \n");
balance=balance + amount1;
printf("Your current balance is %d\n",balance);
}
else
printf("Invalid amount\n");
printf("Enter 10 for another transaction and 20 to return to the main menu :");
scanf("%d",&x);
if(x==20)
break;
if(x==10)
continue;
}
}
if(option==2)
{
printf("Balance Enquiry !\n");
printf("Your current balance is %d",balance);
printf("Enter 10 for another withdraw transaction and 20 for main menu : ");
scanf("%d",&y);
if(y==20)
break;
if(y==10)
continue;
}
if(option==3)
{
printf("Your current balance is %d\n",balance);
for(k=1;k<4;k++)
 {
printf("Enter amount that is greater than 1000, less than 20,000 and a multipleof 500 : ");
scanf("%d",&amount2);
if(amount2>1000&&amount2<20000)
{
printf("Please take your amount \n");
balance=balance-amount2;
printf("Your current balance is %d\n",balance);
}
else
printf("Invalid amount");
printf("Enter 10 for another withdraw transaction and 20 for main menu : ");
scanf("%d",&y);
if(y==20)
break;
if(y==10)
continue;
 }
}
if(option==4)
{
 for(; ;)
 {
printf("Change Pin\n");
printf("Enter your 4 digit new pin: ");
scanf("%d",&npin);
printf("Re-enter the new pin: ");
scanf("%d",&rpin);
if(npin==rpin)
{
printf("PIN has been successfully changed\n");
}
else
{
printf("PIN does not match\n");
}
printf("Enter 100 for another try of pin change and 0 for main menu : ");
scanf("%d",&z);
if(z==0)
break;
if(z==100)
continue;
 }
}
if(option==5)
{
printf("Total number of withdraw transcations : %d\n",k);
printf("Total amount withdrawn : %d\n",amount2);
printf("Total number of deposit transactions : %d\n",j);
printf("Total amount deposited : %d\n",amount1);
printf("Current balance : %d\n",balance);
printf("Thanks\n");
exit(0);
}
}
getchar();
return 0;
}
