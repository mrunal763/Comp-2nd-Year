#include <iostream>
#include <fstream>
using namespace std;

class employee
{

 int id;
 char Name[30];
 char Designation[30];
 char Salary[10];
	

public:
 void accept();
 void display();
 int ID()
 {
  return id;
 }
	
};


void employee::accept()
{
 cout<<"\nEnter ID: ";
 cin>>id;

 cout<<"\nEnter Name: ";
 cin.ignore();
 cin.getline(Name,30);
	
 cout<<"\nEnter Designation: ";
 cin>>Designation;
	
 cout<<"\nEnter Salary: ";
 cin>>Salary;

 cout<<"\n";
}


void employee::display()
{
 cout<<"\n "<<id<<"\t "<<Name<<" \t\t "<<Designation<<"\t "<<Salary;
}


void create()
{
 employee s;
 int n, i;

 ofstream out("employee.txt");
 cout<<"\nHow many records do you want to enter?: ";
 cin>>n;

 for(i=0;i<n;i++)
 {
  s.accept();
  out.write((char *)&s,sizeof(s));
 }

 out.close();
}



void search()
{
 int n, flag=0;

 cout<<"\nEnter ID To Be Searched: ";
 cin>>n;
 ifstream infile("employee.txt");

 employee s;
 while(infile.read((char *)&s,sizeof(s)))
 {
  if(s.ID()==n)
  {
   cout<<"\nRecord Found\n";
   cout<<"\nID Name Designation Salary";
   s.display();
   flag=1;
   break;
  }
 }

 if(flag==0)
 {
  cout<<"\nRecord Not Found.";
 }

 infile.close();
}



void display()
{
 employee s;
 ifstream infile("employee.txt");
 while(infile.read((char *)&s, sizeof(s)))
 {
  s.display();
 }

 infile.close();
}


void add_record()
{
 employee s;
 ofstream outfile("employee.txt",ios::app);
 s.accept();
 outfile.write((char *)&s,sizeof(s));
 outfile.close();
 cout<<"Record Successfully Added.";
}




void delete_record()
{
 int n, flag=0;
 cout<<"\nEnter ID Whose Record To Be Deleted:";
 cin>>n;
 ifstream infile("employee.txt");
 ofstream temp("temp.txt"); 
 employee s;
 while(infile.read((char *)&s, sizeof(s)))
 {
  if(s.ID()!=n)
  {
   temp.write((char *)&s, sizeof(s));
  }

  else
  {
   flag=1;
   cout<<"\nRecord Successfully Deleted.";
  }
 }

  if(flag==0)
  {
   cout<<"\nRecord Not Found.";
  }

  infile.close();
  temp.close();
  remove("employee.txt");
  rename("temp.txt","employee.txt");
}



int main()
{
 int choice,id;
 char Name[30];
 ofstream out("employee.txt");
 out.close();
 do
 { cout<<"\n";
  cout<<"\nMenu:\n1) Create Database.\n2) Display.\n3) Add record.\n4) Search Record.\n5)Delete Record.\n6) Exit.";
  cout<<"\n\nEnter Your Choice: ";
  cin>>choice;

  switch(choice)
  {
   case 1:
    cout<<"\n";
    create();
    break;

   case 2:
    cout<<"\n";
    cout<<"\nID Name Designation Salary";
    display();
    break;

   case 3:
    cout<<"\n";
    add_record();
    break;

   case 4:
    cout<<"\n";
    search();
    break;
  
   case 5:
    cout<<"\n";
    delete_record();
    break;

   case 6:
    cout<<"\n";
    cout<<"You Have Successfully Exitted...";
    exit(0);
    break;
  } 
 }
 while(choice!=7);

 return 0;
}
