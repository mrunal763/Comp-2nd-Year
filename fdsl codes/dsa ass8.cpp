#include<iostream>
#include<conio.h>
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
}
else
{
}
}
cout<<"Enter data:";
cin>>x;
r=r+1;
a[r]=x;
display();
cout<<"Queue is full\n";
int del()
{
int x;
if(!isempty())
{
}
else
{
}
x=a[f];
f=f+1;
display();
cout<<"Queue is empty\n";
return x;
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
clrscr();
int ch,x;
init();
while(1)
{
cout<<"\n\nMenu\n1.Insert\n2.Delete\n3.Exit\nEnter choice:";
cin>>ch;
switch(ch)
{
case 1:
break;
case 2:
break;
case 3:
}
}
}
insert();
del();
return 0;
