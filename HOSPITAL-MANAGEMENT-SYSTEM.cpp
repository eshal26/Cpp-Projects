#include<iostream>
#include<string.h>
#include<iomanip>
#include<cstdlib>
#include<time.h>
#include<fstream>
using namespace std;
class Person{
	protected:
	char name[20];
	char gender[10];
	int age;
	string date;
	int person_id;
	long long phone_no;
	char city[20];
	char b_group[20];
	public:
		void person_data()
		{
			cout<<"\n\n";
			cout<<"\t\t\tEnter name : ";
			cin>>name;
			cout<<"\t\t\tEnter gender : ";
			cin>>gender;
			cout<<"\t\t\tEnter age : ";
			cin>>age;
			cout<<"\t\t\tEnter Person ID : ";
			cin>>person_id;
			cout<<"\t\t\tEnter Phone number : ";
			cin>>phone_no;
			cout<<"\t\t\tEnter City : ";
			cin>>city;
			cout<<"\t\t\tEnter blood group : ";
			cin>>b_group;
		}
		void display_data()
		{
			cout<<"\t\t\tName : "<<name<<endl;
			cout<<"\t\t\tGender : "<<gender<<endl;
			cout<<"\t\t\tAge : "<<age<<endl;
			cout<<"\t\t\tPerson ID : "<<person_id<<endl;
			cout<<"\t\t\tPhone number : "<<phone_no<<endl;
			cout<<"\t\t\tCity : "<<city<<endl;
			cout<<"\t\t\tBlood group : "<<b_group<<endl;
		}
};
class Staff:public Person
{
	int salary;
	string date_from;
	char post[20];
	public:
		void staff_data()
		{
			person_data();
			cout<<"\t\t\tPost : ";
			cin>>post;
			cout<<"\t\t\tEnter Salary : ";
			cin>>salary;
			cout<<"\t\t\tEnter date of employment : ";
			cin>>date_from;
		}
		void display_staff()
		{
			display_data();
			cout<<"\t\t\tPost "<<post<<endl;
			cout<<"\t\t\tSalary : "<<salary<<endl;
			cout<<"\t\t\tDate of employment : "<<date_from<<endl;
		}
};
class Patient:public Person{
	private:
		char appointment[20];
	public:
		void add_patient()
		{
			person_data();
			cout<<"\t\t\tEnter Appointment : ";
			cin>>appointment;
			
		
		}
		void display_patient()
		{
			display_data();
			cout<<"\t\t\tAppointment : "<<appointment<<endl;
			
		}
	
};
class Receptionist:public Person{
	Patient p1;
	public:
	void add_pdata()
	{
		p1.add_patient();
		ofstream File("myfile.txt");
		File.open("myfile.txt",ios::app);
		    File<<"\nPatient name : "<<name;
			File<<"\nPatient age : "<<age;
			File<<"\nPatient Gender : "<<gender;
		    File.close();
	}
	void show_pdata()
	{
		p1.display_patient();
		string text;
		ifstream readFile("myfile.txt");
		while(getline(readFile,text))
		{
			cout<<text;
		}
		readFile.close();
	}


};
class Doctor:public Person{
	double salary;
    char date_from[50];
    char specializtion[20];
    
    public:
        void doctor_data()
		{
			person_data();
			cout<<"\t\t\tSpecialization : ";
			cin>>specializtion;
			cout<<"\t\t\tSalary : ";
			cin>>salary;
			cout<<"\t\t\tDate of employment :  ";
			cin>>date_from;
		}
		void display_doctor()
		{
			display_data();
			cout<<"\t\t\tSpecialization : "<<specializtion<<endl;
			cout<<"\t\t\tSalary : "<<salary<<endl;
			cout<<"\t\t\tDate of employment : "<<date_from<<endl;
		}
    	
};
class store_manager{
	
};
class Admin{
	Doctor d;
	Staff sf;
	Receptionist r;
	store_manager s;
	Patient p;
public:
	void add_staff()
	{
		sf.staff_data();
	}
	void show_staff()
	{
		sf.display_staff();
	}
	void add_doctor()
	{
		d.doctor_data();
	}
	void show_doctor()
	{
		d.display_doctor();
	}
};
void reception_menu()
{
	
	reception:
		Receptionist r1;
			int PIN2;
			cout<<"\n\t\tEnter PIN for Receptionist : ";
			cin>>PIN2;
			int ch1;
			if(PIN2==2222)
			{
				    reception1:
						int ch2;
					    cout<<"\n\n";
					    cout<<"\t\t1.Patient Check-In\n";
					    cout<<"\t\t2.Patient Check-Out\n";
					    cout<<"\t\t3.View all Patient Data\n";
					    cin>>ch2;
					    system("cls");
					    if(ch2==1)
					    {
					    	addp:
					    	cout<<"\n\t\t\tADD PATIENT DATA : "<<endl;
					    	r1.add_pdata();
					    	int v;
					    	cout<<"1.Enter Main Menu\n";
					    	cout<<"2.Add more patient data\n";
					    	cin>>v;
					    	if(v==1)
					    	goto reception1;
					    	if(v==2)
					    	goto addp;
					    	system("cls");
						}
						if(ch2==2)
						{
							int pid;
							cout<<"Enter Patient ID : ";
							cin>>pid;
							
							
						}
						if(ch2==3)
						{
							r1.show_pdata();
					    }
				
			}
			else
			{
				cout<<"\n\t\tWRONG PIN. TRY AGAIN\n\n";
			    system("pause");
			    system("cls");
				goto reception;
			}
}
int main()
{
	cout<<"\n\n\n\n";
	cout<<"\t\t\t\t"<<"----------------------------------------------------------------------\n";
	cout<<"\t\t\t\t"<<"|                       WELCOME         TO                           |\n";
	cout<<"\t\t\t\t"<<"|                                                                    |\n";
	cout<<"\t\t\t\t"<<"|               HOSPITAL        MANAGEMENT        SYSTEM             |\n";
	cout<<"\t\t\t\t"<<"----------------------------------------------------------------------\n";
	system("pause");
	system("cls");
	cout<<"\n\n\n";
	int option;
	Admin a1;
	cout<<setw(10)<<"MENU\n\n";
	cout<<setw(20)<<"1. >> Admin\n";
	cout<<setw(27)<<"2. >> Recepsionist\n";
	cout<<setw(21)<<"3. >> Doctor\n";
	cout<<setw(28)<<"4. >> Store Manager\n";
	cout<<setw(19)<<"5. >> Exit\n";
	cout<<setw(40)<<"\n\tLOGIN AS : \n";
	cin>>option;
	system("cls");
	switch(option)
	{
		case 1:	
		    admin:
		    int PIN1;
		    cout<<"\n\t\tEnter PIN for admin : ";
		    cin>>PIN1;
		    if(PIN1==1111)
		    {
		    	admin1:
		    	int a;
		    	cout<<"\n";
		    	cout<<"\t\t1.Manage Staff Data\n";
		    	cout<<"\t\t2.Manage Doctor Data\n";
		    	cout<<"\t\t3.Manage Store Data\n";
		    	cout<<"\t\t4.View Patient Data\n";
		    	cout<<"\t\t5.Manage Hospital Expenses\n";
		    	cout<<"\t\t6.EXIT system\n";
		    	cout<<"\t\tChoose one : ";
		    	cin>>a;
		    	switch(a)
		    	{
		    		case 1:
		    			staff:
		    			int w;
		    			cout<<"\n\t\t1.Add Staff Data :";
		    			cout<<"\t\t2.View Staff Data : ";
		    			cin>>w;
		    			if(w==1)
		    			a1.add_staff();
		    			if(w==2)
		    			a1.show_staff();
		    			int w1;
		    			cout<<"\n\t\t1.Return to main menu";
		    			cout<<"\n\t\t2.Return to manage staff data\n";
		    			cin>>w1;
		    			system("cls");
		    			if(w1==1)
		    			goto admin1;
		    			if(w1==2)
		    			goto staff;
		    			break;
		    		case 2:
		    			doctor:
		    		    int v;
		    			cout<<"\n\t\t1.Add Doctor Data :";
		    			cout<<"\t\t2.View Doctor Data : ";
		    			cin>>v;
		    			if(v==1)
		    			a1.add_doctor();
		    			if(v==2)
		    			a1.show_doctor();
		    			int w2;
		    			system("cls");
		    			cout<<"\n";
		    			cout<<"\n\t\t1.Return to main menu";
		    			cout<<"\n\t\t2.Return to manage doctor data\n";
		    			cin>>w2;
		    			system("cls");
		    			if(w2==1)
		    			goto admin1;
		    			if(w2==2)
		    			goto doctor;
		    			break;
		    		case 6:
		    			exit(0);
		    		default:
		    			cout<<"\nChoose Correct Option\n";
				}
			}
			else
			{
				cout<<"\n\t\tWRONG PIN. TRY AGAIN\n\n";
			    system("pause");
			    system("cls");
				goto admin;
			}
			break;
		case 2:
		    reception_menu();
			break;
		case 3:
		    break;
		case 4:
			exit(0);
		default:
			cout<<"\nPlease choose correct option.\n";
	}
	return 0;
}