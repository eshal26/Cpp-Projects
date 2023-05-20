#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct inventory_item{
	char name[20];
	int id;
	int qty;
	float price;
	inventory_item *nptr;
};
inventory_item *fptr=NULL;
int main()
{
	int n,count=0;
	while(1)
	{
		cout<<"\nInventory Management Database\n\n";
		cout<<"Main menu\n";
	    cout<<"1.Add inventory item\n2.Sell inventory item\n3.Buy inventory from supplier\n4.Check Stocks\n5.Exit\n"<<endl;
	    cout<<"Choose your preference : ";
	    cin>>n;
	    if(n==1)
	    {
	    	int id;
	    	inventory_item *ptr;
	    	ptr=new inventory_item;
	    	if(fptr==NULL)
	    	{
	    	   	fptr=ptr;
	    	   	ptr->nptr=NULL;
			}
			else{
				inventory_item *cptr;
				cptr=fptr;
				while(cptr->nptr!=NULL)
				{
					cptr=cptr->nptr;
				}
				ptr->nptr=NULL;
				cptr->nptr=ptr;
			
			}
			
			cout<<"\nEnter id of item : ";
			cin>>id;
			inventory_item *f2;
			f2=new inventory_item;
			f2=fptr;
			while(f2!=NULL)
			{
			 if(id==f2->id)
			 {
			 	count++;
			 	cout<<"\nThis ID is already taken. \n";
				break;
			 }
			 f2=f2->nptr;
		    }
			if(count==0)
			{
			  ptr->id=id;
			  cout<<"\nEnter name of item : ";
			  cin>>ptr->name;
			  cout<<"\nEnter quantity of item : ";
			  cin>>ptr->qty;
			  cout<<"\nEnter price of item : ";
			  cin>>ptr->price;
		    }
			
		}
		if(n==2)
		{
			int id1,flag=0,qt;
			inventory_item *temp;
			temp=new inventory_item;
			temp=fptr;
			cout<<"\nEnter ID of item : ";
			cin>>id1;
			while(temp!=NULL)
			{
				if(id1==temp->id)
				{
				    cout<<"\nName of item : "<<temp->name<<endl;
					cout<<"\nPrice of item : "<<temp->price<<endl;
					cout<<"\nEnter quantity to sell : \n";
					cin>>qt;
					if(qt<=temp->qty)
					{
						cout<<"\nTotal price is : "<<temp->price*qt<<endl;
						temp->qty=temp->qty-qt;
						cout<<"\nQuantity left : "<<temp->qty<<endl;
			            if(temp->qty<=0)
			            {
			            	inventory_item *f1;
			            	f1=fptr;
				            while(f1!=NULL)
				          {
					       if(f1->qty==temp->qty)
					        {
					            	break;
					        }
					        f1=f1->nptr;
			            }
			           	   if(f1==fptr)
		             	   {
			           	     fptr=f1->nptr;
				             cout<<"\nThis item is removed from system. \n";
			              }
			            else
			            {
			             	inventory_item *f2;
				            f2=new inventory_item;
			             	f2=fptr;
			             	while(f2!=NULL)
			               	{
					           if(f2->nptr->qty==f2->qty)
					           {
					            	break;
					           }
					            f2=f2->nptr;
			               	}
				             f2->nptr=f2->nptr->nptr;
				             cout<<"\nThis item is removed from system. \n";
			                }
		                }
						break;
					}
					else
					{
						cout<<"\nNot enough stock \n";
						break;
					}
				}
				else{
					cout<<"\nNo item matched. \n";
					break;
				}
			}
				
				}
				
		if(n==3)
		{
			int id2;
			int q1,c=0;
			inventory_item *find;
			find=new inventory_item;
			find=fptr;
			cout<<"\nEnter ID of item : ";
			cin>>id2;
			cout<<"Enter Quantity : ";
			cin>>q1;
			while(find->nptr!=NULL)
			{
				if(id2==find->id)
				{
					c++;
					break;
				}
				find=find->nptr;
			}
			if(c!=0)
			{
			find->qty=find->qty + q1;
			cout<<"\nQuantity of "<<find->name<<" is now : "<<find->qty<<endl;
	     	}
		    else if(c==0)
		    {
		    	cout<<"\nNo ID matched. \n";
			}
			
		}
		if(n==4)
		{
			int i;
			i=0;
			inventory_item *cptr;
			cptr=new inventory_item;
			cptr=fptr;
			if(cptr==NULL)
			{
				cout<<"\nNo data found! \n";
			}
			while(cptr!=NULL)
			{
				i++;
				 cout<<"\nId of item "<<i<<" : "<<cptr->id<<endl;
				 cout<<"Name of item : "<<cptr->name<<endl;
				 cout<<"Quantity of item : "<<cptr->qty<<endl;
				 cout<<"Price of item : "<<cptr->price<<endl;
				 cout<<endl;
			     cptr=cptr->nptr;	
			}
			int sum=0;
		    inventory_item *f1;
		    f1=new inventory_item;
		    f1=fptr;
			while(f1!=NULL)
			{
				sum=sum+f1->price*f1->qty;
				f1=f1->nptr;
			}
			cout<<"\nTotal Stock Value is : "<<sum<<endl;
			
		}
		if(n==5)
		{
			exit(0);	
		}
	}
	return 0;
}
