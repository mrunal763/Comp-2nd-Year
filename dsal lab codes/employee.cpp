/*
Problem Statement :Company maintains employee information as employee ID, name, 
designation and salary. Allow user to add, delete information of employee. 
Display information of particular employee. If employee does not exist an appropriate message is displayed. 
If it is, then the system displays the employee details.
 Use index sequential file to maintain the data.
*/

#include <iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;

const int MAX=20;
class Employee
{
    int empid;
    char name[20],city[20];
    char role[20];
    int salary;
    public:
        Employee()
        {
            strcpy(name,"");
            strcpy(city,"");
            empid=salary=0;
        }
        Employee(int empid,char name[MAX],int salary,char role[MAX],char city[MAX])
        {
            strcpy(this->name,name);
            strcpy(this->city,city);
            this->empid=empid;
            this->salary=salary;
            strcpy(this->role,role);
        }
        int getRollNo()
        {
            return empid;
        }
        void displayRecord()
        {
            cout<<endl<<setw(5)<<empid<<setw(20)<<name<<setw(5)<<salary<<setw(5)<<role<<setw(10)<<city;
    }
};

//==========File Operations ===========
class FileOperations
{
    fstream file;
    public:
        FileOperations(char* filename)
        {
            file.open(filename,ios::in|ios::out|ios::ate|ios::binary);
        }
        void insertRecord(int empid, char name[MAX],int salary, char role[20],char city[MAX])
        {
            Employee e1(empid,name,salary,role,city);
            file.seekp(0,ios::end);
            file.write((char *)&e1,sizeof(Employee));
            file.clear();
        }
        void displayAll()
        {
            Employee e1;
            file.seekg(0,ios::beg);
            while(file.read((char *)&e1, sizeof(Employee)))
            {
                e1.displayRecord();
            }
            file.clear();
        }
        void displayRecord(int empid)
        {
            Employee e1;
            file.seekg(0,ios::beg);
            bool flag=false;
            while(file.read((char*)&e1,sizeof(Employee)))
            {
                if(e1.getRollNo()==empid)
                {
                    e1.displayRecord();
                    flag=true;
                    break;
                }
            }
            if(flag==false)
            {
                cout<<"\nRecord of "<<empid<<"is not present.";
            }
            file.clear();
        }
        void deleteRecord(int empid)
        {
        ofstream outFile("new.dat",ios::binary);
        file.seekg(0,ios::beg);
        bool flag=false;
        Employee e1;
        while(file.read((char *)&e1, sizeof(Employee)))
        {
        if(e1.getRollNo()==empid)
        {
            flag=true;
            continue;
        }
        outFile.write((char *)&e1, sizeof(Employee));
        }
        if(!flag)
        {
            cout<<"\nRecord of "<<empid<<" is not present.";
        }
        file.close();
        outFile.close();
        remove("Employee.dat");
        rename("new.dat","Employee.dat");
        file.open("Employee.dat",ios::in|ios::out|ios::ate|ios::binary);
        }
        ~FileOperations()
        {
            file.close();
            cout<<"\nFile Closed.";
        }
};

int main() 
{
    ofstream newFile("Employee.dat",ios::app|ios::binary);
    newFile.close();
    FileOperations file((char*)"Employee.dat");
    int empid,salary,choice=0;
    char role[20];
    char name[MAX],address[MAX];
    while(choice!=5)
    {
        //clrscr();
        cout<<"\n*****Employee Database*****\n";
        cout<<"1) Add New Record\n";
        cout<<"2) Display All Records\n";
        cout<<"3) Display by Employee ID\n";
        cout<<"4) Deleting a Record\n";
        cout<<"5) Exit\n";
        cout<<"Choose your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 : //New Record
                cout<<endl<<"Enter Employee ID and name : \n";
                cin>>empid>>name;
                cout<<"Enter Salary and Designation : \n";
                cin>>salary>>role;
                cout<<"Enter address : \n";
                cin>>address;
                file.insertRecord(empid,name,salary,role,address);
                cout<<"\nRecord Inserted.";
                break;
            case 2 :
                cout<<endl<<setw(5)<<"ID"<<setw(20)<<"NAME"<<setw(5)<<"SALARY"<<setw(5)<<"ROLE"<<setw(10)<<"CITY";
                file.displayAll();
                break;
            case 3 :
                cout<<"Enter Employee ID:";
                cin>>empid;
                file.displayRecord(empid);
                break;
            case 4:
                cout<<"Enter Employee ID:";
                cin>>empid;
                file.deleteRecord(empid);
                break;
            case 5 :
                break;
        }

    }
return 0;
}

