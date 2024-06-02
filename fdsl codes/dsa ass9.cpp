#include<iostream>
using namespace std;
void init();
void insert();
int full();
int isempty();
void display();
int a[5],f,r;
void init()
{
	f=-1;
	r=-1;
}
void insert()
{
	int x;
	if(f==-1)
	{
		f=0;
	}
	if(!full())
	{
		cout<<"Enter data:";
		cin>>x;
		r=r+1;
		a[r]=x;
		display();	
	}
	else
	{
		cout<<"Queue is full\n";
	}
}
int del()
{
	int x;
	if(!isempty())
	{
		x=a[f];
		f=f+1;
		display();
	}
	else
	{
		cout<<"Queue is empty\n";
	}
}
int full()
{
	if(r==4)
		return 1;
	return 0;
}
int isempty()
{
	if(f==-1 || f==r+1)
		return 1;
	return 0;
}
void display()
{
	int i;
	cout<<"\nQueue=";
	for(i=f;i<=r;i++)
	{
		cout<<"\t"<<a[i];
	}
}
int main()
{
	int ch,x;
	init();
	while(1)
	{
		cout<<"\n\nMenu\n1,Insert\n2.Delete\n3.Exit\nEnter choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				insert();
			break;
			case 2:
				del();
			break;
			case 3:
				return 0;
		}
	}
}

