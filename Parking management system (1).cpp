#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
#include<fstream>
#include<sstream>
using namespace std;
struct vehicle{
	int regno;
	string dname;
	string make;
	string model;
	string color;
	time_t entry_time;
	vehicle *nptr;
};
struct LinkedList{
	vehicle *fptr;
};
fstream myfile;
int sum;
time_t start,finish;
vehicle *fptr=NULL;
void vehicle_entry();
void vehicle_exit();
void parking_fee();
void parking_statistics();
void del_vehicle(vehicle *temp);
void write_file();
void read_file();
int main()
{
	read_file();
	int n;
	sum=0;
	while(1)
  {
  	cout<<"\n\t\t-----------------------------------------\t\t\n";
	cout<<"\n\t\t\tPARKING MANAGEMENT SYSTEM \n";
	cout<<"\n\t\t-----------------------------------------\t\t\n";
	cout<<"\n\tMENU\n\n";
	cout<<"1.Vehicle Entry\n2.Vehicle Exit\n3.Parking fee Collected\n4.Parking statistics\n5.Exit\n";
	cout<<"Choose your preference : ";
	cin>>n;
	switch(n)
	{
		case 1:
			vehicle_entry();
			system("pause");
			system("cls");
			cout<<endl;
			break;
		case 2:
			vehicle_exit();
			cout<<endl;
			system("pause");
			system("cls");
		    break;
		case 3:
			parking_fee();
			cout<<endl;
			system("pause");
			system("cls");
		    break;
		case 4:
			parking_statistics();
			cout<<endl;
			system("pause");
			system("cls");
		    break;
		case 5:
			write_file();
		    exit(0);
			 
				}
	}
				
}
void read_file()
{
    myfile.open("Parking_Data2.txt", ios::in);
string line;
    if (myfile) {
        
        while (getline(myfile, line)) {
            vehicle *ptr = new vehicle;
            istringstream ss(line);
            ss >> ptr->regno >> ptr->dname >> ptr->make >> ptr->model >> ptr->color;
            ptr->nptr = NULL;

            if (fptr == NULL) {
                fptr = ptr;
            } else {
                vehicle *cptr = fptr;
                while (cptr->nptr != NULL) {
                    cptr = cptr->nptr;
                }
                cptr->nptr = ptr;
            }
        }
        myfile.close();
    } else {
        cout << "Error: unable to open file for reading\n";
    }
}

void write_file()
		{
			myfile.open("Parking_Data2.txt",ios::out);
			vehicle *cptr;
	        cptr=fptr;
	        myfile<<"\nVehicles currently parked\n";
	        if(!myfile)
	        {
	        	cout<<"\nFILE IS NOT CREATED\n";
	        }
	        else
	        {
	        if(cptr==NULL)
	       {
	     	myfile<<"\nParking Area is empty. \n";
	       }
	       while(cptr!=NULL)
	   {
		myfile<<"\nRegistration number of vehicle : "<<cptr->regno<<endl;
		myfile<<"Driver name of vehicle : "<<cptr->dname<<endl;
		myfile<<"Make of vehicle : "<<cptr->make<<endl;
		myfile<<"Model of vehicle : "<<cptr->model<<endl;
		myfile<<"Color of vehicle: "<<cptr->color<<endl;
		cptr=cptr->nptr;
	    }
			myfile.close();
			myfile.open("Parking_Data2.txt",ios::in|ios::binary);
			string text;                           
			cout<<"\nContent of file : ";
			cout<<endl;
			while (getline(myfile, text))
            {
                cout << text << endl;
            }
			myfile.close();
}	
}
void vehicle_entry()
{
	vehicle *ptr;
	ptr=new vehicle;
	if(fptr==NULL)
	{
		fptr=ptr;
		ptr->nptr=NULL;
	}
	else
	{
		vehicle *cptr=fptr;
		while(cptr->nptr!=NULL)
		{
			cptr=cptr->nptr;
		}
		cptr->nptr=ptr;
		ptr->nptr=NULL;
		
	}
	cout<<"\nEnter Registration number of vehicle : ";
	cin>>ptr->regno;
	cout<<"Enter Driver's name : ";
	cin>>ptr->dname;
	cout<<"Enter vehicle's material : ";
	cin>>ptr->make;
	cout<<"Enter vehicle model : ";
	cin>>ptr->model;
	cout<<"Enter vehicle color : ";
	cin>>ptr->color;
	cout<<"Vehicle Entry time : ";
	time(&start);
	time_t t; // t passed as argument in function time()
    struct tm * tt; // decalring variable for localtime()
    time (&t); //passing argument to time()
    tt = localtime(&t);
    cout << "Current Day, Date and Time is = "<< asctime(tt);
    //ptr->entry_time=gettime();
    //cout<<ptr->entry_time;
	
}
void vehicle_exit()
{
	int regno;
	bool b=false;
	cout<<"\nEnter registration number of vehicle : ";
	cin>>regno;
	vehicle *temp;
	temp=fptr;
	while(temp!=NULL)
	{
		if(regno==temp->regno)
		{
			b=true;
			break;
		}
		temp=temp->nptr;
	}
	if(b==true)
	{
		cout<<"\nVehicle Exit time : \n";
		time(&finish);
	    time_t t; // t passed as argument in function time()
        struct tm * tt; // decalring variable for localtime()
        time (&t); //passing argument to time()
        tt = localtime(&t);
        cout << "Current Day, Date and Time is = "<< asctime(tt)<<endl;
        int ti,pkr;
        ti=difftime(finish,start);
        if(ti<60)
        {
        	pkr=50;
        	cout<<"\nCollect "<<50<<" Rupees amount from Car Reg No. "<<temp->regno<<endl;
		}
		else
		{
		pkr=70;
		cout<<"\nCollect "<<70<<" Rupees amount from Car Reg No. "<<temp->regno<<endl;
	   }
	   del_vehicle(temp);
	sum=sum+pkr;
	}
	else
	{
		cout<<"\nNo vehicle in record of this Registration Number\n";
	}
	
}
void parking_fee()
{
	cout<<"\nTotal Parking fee : "<<sum<<endl;
	
}
void parking_statistics()
{
	vehicle *cptr;
	cptr=fptr;
	cout<<"\nVehicles currently parked\n";
	if(cptr==NULL)
	{
		cout<<"\nParking Area is empty. \n";
	}
	while(cptr!=NULL)
	{
		cout<<"\nRegistration number of vehicle : "<<cptr->regno<<endl;
		cout<<"Driver name of vehicle : "<<cptr->dname<<endl;
		cout<<"Model of vehicle : "<<cptr->model<<endl;
		cout<<"Color of vehicle : "<<cptr->color<<endl;
		cout<<"Material of vehicle: "<<cptr->make<<endl;
		cptr=cptr->nptr;
	}
}
void del_vehicle(vehicle *temp)
{
	if(fptr==temp)
	{
		fptr=temp->nptr;
		delete temp;
	}
	else
	{
		vehicle *cptr;
		cptr=fptr;
		while(cptr->nptr!=temp)
		{
			break;
		}
		cptr->nptr=cptr->nptr->nptr;
		delete temp;
	}
}

