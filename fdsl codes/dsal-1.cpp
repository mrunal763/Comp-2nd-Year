#include <iostream>
#include <fstream>
using namespace std;

class student
{

 int roll_no;
 char Name[30];
 char Division[5];
 char Address[50];
	

public:
 void accept();
 void display();
 int rollno()
 {
  return roll_no;
 }
	
};


void student::accept()
{
 cout<<"\nEnter Roll Number: ";
 cin>>roll_no;

 cout<<"\nEnter Name: ";
 cin.ignore();
 cin.getline(Name,30);
	
 cout<<"\nEnter Division: ";
 cin>>Division;
	
 cout<<"\nEnter Address: ";
 cin>>Address;

 cout<<"\n";
}


void student::display()
{
 cout<<"\n "<<roll_no<<"\t "<<Name<<" \t\t "<<Division<<"\t "<<Address;
}


void create()
{
 student s;
 int n, i;

 ofstream out("Student.txt");
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

 cout<<"\nEnter Roll Number To Be Searched: ";
 cin>>n;
 ifstream infile("Student.txt");

 student s;
 while(infile.read((char *)&s,sizeof(s)))
 {
  if(s.rollno()==n)
  {
   cout<<"\nRecord Found\n";
   cout<<"\nRoll Number Name Division Address";
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
 student s;
 ifstream infile("Student.txt");
 while(infile.read((char *)&s, sizeof(s)))
 {
  s.display();
 }

 infile.close();
}


void add_record()
{
 student s;
 ofstream outfile("Student.txt",ios::app);
 s.accept();
 outfile.write((char *)&s,sizeof(s));
 outfile.close();
 cout<<"Record Successfully Added.";
}




void delete_record()
{
 int n, flag=0;
 cout<<"\nEnter Roll Number Whose Record To Be Deleted:";
 cin>>n;
 ifstream infile("student.txt"); // to read from source file
 ofstream temp("temp.txt"); // to write in destination file(temporary file)
 student s;
 while(infile.read((char *)&s, sizeof(s)))
 {
  if(s.rollno()!=n)
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
  remove("Student.txt");
  rename("temp.txt","Student.txt");
}



int main()
{
 int choice,roll_no,Marks;
 char Name[30];
 ofstream out("Student.txt");
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
    cout<<"\nRoll Number Name Division Address";
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
    break;
  } 
 }
 while(choice!=5);

 return 0;
}
